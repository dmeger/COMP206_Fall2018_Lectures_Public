#!/bin/bash
#
# A first example for loop
# Very often we want to loop over the files in a 
# directory and do the same thing to all of them.
#
# This script changes the extension of all files
# in a sub-directory to ".dat".
#

for f in `ls directory_of_sample_files`
do

  echo The file was named $f
  
  without_ext=$(echo $f | cut -d. -f1)
  new_name=${without_ext}.dat
  
  echo I will move it to $new_name  
  
  mv directory_of_sample_files/${f} directory_of_sample_files/${new_name}
  
done

