
PROGRAMS = init release customer producer

all: $(PROGRAMS)

customer: customer.c
	gcc customer.c -lpthread -o $@
producer: producer.c
	gcc producer.c -lpthread -o $@
init: init.c
	gcc init.c -lpthread -o $@
release: release.c
	gcc release.c -lpthread -o $@

clean:
	rm $(PROGRAMS)
