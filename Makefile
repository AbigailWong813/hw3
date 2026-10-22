CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS=llrec-test.o llrec.o 

all: llrec-test stack-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

llrec.o: llrec.cpp llrec.h 
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp

stack-test: stack-test.o
	$(CXX) $(CXXFLAGS) -o $@ stack-test.o

stack-test.o: stack_test.cpp stack.h
	$(CXX) $(CXXFLAGS) -o $@ -c stack_test.cpp

clean:
	rm -f *.o rh llrec-test stack-test *~

.PHONY: clean 