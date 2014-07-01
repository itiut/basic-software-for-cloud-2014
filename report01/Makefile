TARGETS := a.out Main.class Stencil.class

all: $(TARGETS)

a.out: stencil.c
	gcc -std=c99 -O3 $<

.SUFFIXES: .java .class
.java.class:
	javac $<

clean:
	rm -f $(TARGETS)
