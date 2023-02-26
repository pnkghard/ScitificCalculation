set terminal postscript
set output 'plot.eps'
set xlabel 'x-axis label'
set ylabel 'y-axis label'
plot 'stencil_out.dat' using 1:2 with lines title 'Pankaj'
