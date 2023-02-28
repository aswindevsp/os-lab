#!/bin/sh

printf "Enter a number: "
read a

cpy=$a
temp=0

while [ $cpy -ne 0 ]
do 
	rem=$((cpy%10))
	temp=$((rem + (temp * 10)))
	cpy=$((cpy / 10))
done

if [ $temp -eq $a ]
then 
	echo "Given number is a palindrome"
else 
	echo "Given number is not a palindrome"
fi
