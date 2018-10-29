compile: random_write.o
	gcc random_write.o

run:
	./a.out

random_write.o:
	gcc -c random_write.c

clean:
	-rm -rf ./a.out *.o

all:
	make clean
	make
	make run
