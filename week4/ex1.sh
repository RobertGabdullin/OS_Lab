#!/bin/bash
gcc ex1.c -o ex1
for run in {1..10}; do ./ex1; done
