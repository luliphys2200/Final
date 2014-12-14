GRAPH = gnuplot

CC = clang
CFLAGS = -Wall -O0 -g 
LFLAGS = -O0 -g
LIBS = -lgsl -lm

problem2: problem2-main.o problem2-ode.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

problem2-res: problem2
	./problem2 > problem2-res

problem2.png: problem2.gpl problem2-res
	$(GRAPH) problem2.gpl

clean : 
	rm -f *~
	rm -f *.o
	rm -f problem2

veryclean : clean
	rm -f problem2-res problem2.png
