CC = g++
CCFLAGS = -Wall -Werror
Assignment8:assign8.o Rational.o
	$(CC) -o  Assignment8 $(CCFLAGS) assign8.o Rational.o
assign8.o:assign8.cc Rational.cc Rational.h
	$(CC) -c $(CCFLAGS) -std=c++11 assign8.cc
Rational.o:Rational.cc Rational.h
	$(CC) -c $(CCFLAGS) -std=c++11 Rational.cc
run:
	./Assignment8
clean:
	-rm *.o Assignment8
