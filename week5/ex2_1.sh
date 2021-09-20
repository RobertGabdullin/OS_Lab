#!/bin/bash

echo "0" >> test.txt
while :
do
	var1=`tail -1 "./test.txt"`
	LastNum=$((1+var1))
	echo $LastNum >> test.txt
done
