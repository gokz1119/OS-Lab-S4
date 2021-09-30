#! /bin/bash

count=10
if [ $count == 10 ]
then
	echo "Count is 10!"
fi

word=His
if [[ $word == "This" ]]
then
	echo "This is the word"
	echo "Success"
elif [[ $word == "His" ]]
then
	echo "The word is His"
else
	echo "This is not the word"
fi
