# RPN
Simple program for evaluating Reverse Polish notation equations

Compiler: gcc version 5.4.0
OS: Ubuntu 16.04

Building:
$ make 
to build executable pol
$ make clean
to delete executable and object files (actually, are not being generated)
$make test
run some test of program

Testing:
run executable and add equation as an argument in double-quotes, e.g. ./pol "2 2 +"

For now program accepts only integers and works with binary operators +, -, *.

All integer values supported, but that's not accurate. 