#!/bin/sh

printf "Enter a number: "
read a
sum=0

while [ $a -ne 0 ]
do 
	temp=$((a%10))
	sum=$((sum + temp))
	a=$((a / 10))
done

echo "Sum of digits: = $sum "
