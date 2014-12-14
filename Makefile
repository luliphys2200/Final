GRAPH = gnuplot

CC = clang
CFLAGS = -Wall -O0 -g 
LFLAGS = -O0 -g
LIBS = -lgsl -lm

all: problem1.png problem2.png problem3

problem1: problem1-main.o problem1-mc.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)
	
problem1-res: problem1
	./problem1 > problem1-res

problem1.png: problem1.gpl problem1-res
	$(GRAPH) problem1.gpl

problem3: problem3.o
	${CC} $(LFLAGS) -o $@ $^ -lm

problem2: problem2-main.o problem2-ode.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

problem2-res: problem2
	./problem2 > problem2-res

problem2.png: problem2.gpl problem2-res
	$(GRAPH) problem2.gpl

clean : 
	rm -f *~
	rm -f *.o
	rm -f problem1 problem2 problem3

veryclean : clean
	rm -f problem1-res problem1.png problem2-res problem2.png
