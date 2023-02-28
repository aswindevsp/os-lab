#!/bin/sh

while [ true ]
do
	echo "1.Current working dir  2.Todays date  3.List of users"
	printf "Enter a choice: "
	read choice
	case $choice in
		1) pwd;;
		2) date;;
		3) w;;
		*) exit 0;;
	esac
	echo
done
echo $out
