#!/bin/bash

for i in 0 1 2 3 4 5 6 7 8 9
do
	x=`cat file`
	echo $x
	echo $(($x+1)) > file
done

