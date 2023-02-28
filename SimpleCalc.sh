#!/bin/sh

echo "1.Add  2.Substract  3.Multiply  4.Divide"
printf "Enter a choice: "
read choice

printf "Enter the first number: "
read a
printf "Enter the second number: "
read b


case $choice in 
	1) out=`expr $a + $b`;;
	2) out=`expr $a - $b`;;
	3) out=`expr $a * $b`;;
	4) out=`expr $a / $b`;;
esac

echo $out
