#!/bin/bash

if [ "$#" -ne 4 ]; then
	echo "Usage: $0 <cols> <rows> <num_enemies> <num_coins>"
	exit 1
fi

cols=$1
rows=$2
num_enemies=$3
num_coins=$4
total_inner=$(( (rows - 2) * (cols - 2) ))

if [ "$total_inner" -lt $((num_enemies + num_coins + 2)) ]; then
	echo "Not enough space for all elements (need at least $(($num_enemies + $num_coins + 2)))"
	exit 1
fi

# Génère une grille de sol avec bordures
declare -a map
for ((y=0; y<rows; y++)); do
	for ((x=0; x<cols; x++)); do
		if [ $y -eq 0 ] || [ $y -eq $((rows - 1)) ] || [ $x -eq 0 ] || [ $x -eq $((cols - 1)) ]; then
			map[y*cols+x]='1'
		else
			map[y*cols+x]='0'
		fi
	done
done

# Remplit la carte avec éléments aléatoires (C, T, P, E)
fill_random() {
	local symbol=$1
	local count=$2
	local placed=0

	while [ "$placed" -lt "$count" ]; do
		rand=$((RANDOM % total_inner))
		x=$(( (rand % (cols - 2)) + 1 ))
		y=$(( (rand / (cols - 2)) + 1 ))
		index=$((y * cols + x))
		if [ "${map[$index]}" = '0' ]; then
			map[$index]=$symbol
			placed=$((placed + 1))
		fi
	done
}

fill_random "C" "$num_coins"
fill_random "T" "$num_enemies"
fill_random "P" 1
fill_random "E" 1

# Affiche la carte
for ((y=0; y<rows; y++)); do
	for ((x=0; x<cols; x++)); do
		printf "%s" "${map[y*cols+x]}"
	done
	echo
done
