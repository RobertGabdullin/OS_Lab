#!/bin/bash

echo "0" >> test2.txt
ln test2.txt test2.lock
while :
do
        var1=`tail -1 "./test2.lock"`
        LastNum=$((1+var1))
        echo $LastNum >> test2.lock
done
