run: main
	./main sample.c > output.txt
run-out: main
	./main sample.c

test: main-test
	./main-test sample.c > output.txt
test-out: main-test
	./main-test sample.c

main: list.o proj2.o
	gcc list.o proj2.o -o main

main-test: list.o proj2-test.o
	gcc list.o proj2-test.o -o main-test

list.o: list.h list.c
proj2.o: proj2.c list.h
proj2-test.o: proj2-test.c list.h

debug: list.o proj2.o
	gcc -g list.o proj2.o -o main
	./main
