#!/bin/bash
#
# A first simple example with if
# You can try modifying the condition
# such as using the [[  ]] syntax to do 
# the same thing
#

x=$((3*5))

if `test $x -lt 14`
then
  echo Math is borken.
else
  echo Bash can multiply!
fi

echo By the way x=$x.
