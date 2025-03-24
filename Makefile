files := helpers.c main.c player.c sprite.c timer.c 
flags := -Wall -Wextra -Wvla -g -std=c99 -lraylib

main: main.c
	gcc $(files) $(flags)
	
