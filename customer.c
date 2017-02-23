#include <stdio.h>
#include <semaphore.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SEM_NAME "/yutingkao"

sem_t *sem;

void getGlobalSemaphoreFromSharedMemory() {
	sem = sem_open(SEM_NAME, O_CREAT, 0644, 1);
}

int main() {
	getGlobalSemaphoreFromSharedMemory();

	sem_wait(sem);

	int val;

	sem_getvalue(sem, &val);
	printf("Semaphore value is %d\n", val);

	return 0;
}
