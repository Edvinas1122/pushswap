#!/bin/bash
input="steps.txt"
#./stack_sort_game_mac 3 2 1 0
while IFS= read -r line
do
	sleep .5
    exec echo "$line"

done < "$input"
