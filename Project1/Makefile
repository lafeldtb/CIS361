cipher: cipher.o
	gcc cipher.o -o cipher
cipher.o: cipher.c

test: test1 test2
test1:
	./cipher 1 6 data.txt data.out
test2:
	./cipher 2 6 data.out data.bak

test-data: 
	./cipher 1 11 data.txt data.out
	./cipher 1 11 data2.txt data2.out

build: project1.o
	gcc project1.o -o project1
	cp data.out data.bak
build2: project1.o
	gcc project1.o -o project1
	cp data2.out data2.bak
project1.o: project1.c

run: build
	./project1 data.out data.bak
	cat data.out
	diff -s data.out data.txt
run2: build2
	./project1 data2.out data2.bak
	cat data2.out
	diff -s data2.out data2.txt

debug-build:
	gcc -g project1.c -o debug
	cp data.out data.bak

debug: debug-build
	gdb --args debug data.out data.bak

