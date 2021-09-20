#!/bin/bash

echo "0" >> ex2_2.txt
ln ex2_2.txt ex2_2.lock
while :
do
        var1=`tail -1 "./ex2_2.lock"`
        LastNum=$((1+var1))
        echo $LastNum >> ex2_2.lock
done
