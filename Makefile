#
# Makefile for CS 2620 Assignment 1
#
# Author: Jav
# Jan. 11, 2020
#

# some settings
CCC= g++
CCCFLAGS = -Wall -std=c++11

all : test_BTernary
test_BTernary : test_BTernary.o BTernary.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) -c $(CCCFLAGS) $<

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f test_BTernary
