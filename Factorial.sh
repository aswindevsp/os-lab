#!/bin/sh

printf "Enter a number: "
read a

fact=1

while [ $a -ne 0 ] 
do 
	fact=$((fact * a)) 
	a=$((a - 1))
done

echo "Factorial = $fact"
