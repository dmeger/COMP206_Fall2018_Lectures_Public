#!/bin/bash

unsorted_list=$(find $1 -name "*.jpg")

sorted_list=$(ls -tr $unsorted_list)

output_name=$(echo $1 | tr / _)

echo convert -append $unsorted_list $output_name

