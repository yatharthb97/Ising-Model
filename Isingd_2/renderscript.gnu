#!/usr/bin/gnuplot -c

reset
set term pngcairo size 800, 800

set output ARG2

set colorbox
 
set datafile separator ':'
plot ARG1 using 2:3:4 with points pt 6 ps 1 palette

reset