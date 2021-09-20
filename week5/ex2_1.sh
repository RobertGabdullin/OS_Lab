#!/bin/bash

echo "0" >> ex2_1.txt
while :
do
	var1=`tail -1 "./ex2_1.txt"`
	LastNum=$((1+var1))
	echo $LastNum >> ex2_1.txt
done
