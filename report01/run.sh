#!/bin/sh
set -eux

make

./a.out 100 10000 > c.dat
java Main 100 10000 > java.dat

join c.dat java.dat > stencil.dat

gnuplot<<EOPLT
set key below;
set grid;

set xlabel 'iteration'
set ylabel 'Elapsed time [ms]';

set terminal pngcairo enhanced;
set output 'stencil.png';

plot 'stencil.dat' u 1:2 w lp t 'C -O3 memory allocate', \
     'stencil.dat' u 1:3 w lp t 'C -O3 stencil compute', \
     'stencil.dat' u 1:4 w lp t 'Java memory allocate', \
     'stencil.dat' u 1:5 w lp t 'Java stencil compute';
EOPLT
