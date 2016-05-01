# Makefile
# remember: all makefiles are
# target: dependencies
# 	action
# NOTE: the Tab is important
# NOTE: Comentary inline is not allowed
#
#
#all: test

test: test.o list.o
	gcc test.o list.o -o test 

list.o: list.c list.h
	gcc -c list.c

test.o: test.c
	gcc -c test.c

clean: 
	rm *.o test



