#! /bin/bash

echo $1 $2 'echo > $1 $2'

args=("$@")
echo 'Arguments: ' ${args[0]} ${args[1]} ${args[2]}
echo $@

echo 'No. of args: ' $#
