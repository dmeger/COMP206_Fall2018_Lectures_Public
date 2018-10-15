#!/bin/bash

small_code=$(cat $1 | grep a)
large_code=$(cat $1 | grep A)

cat $2 | tr $small_code a-z  | tr $large_code A-Z 

