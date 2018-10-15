#!/bin/bash

small_code=$(cat $1 | grep a)
large_code=$(cat $1 | grep A)

cat $2 | tr a-z $small_code | tr A-Z $large_code

