files := src/main.c src/settings.c src/player.c src/debugging.c src/sprite.c\
	 src/keymaps.c
flags := -std=c99 -Wall -Wextra -Wpedantic -Wvla -g -lraylib

main: src/main.c
	gcc $(files) $(flags) -Iinc/ 

log:
	valgrind --leak-check=full --show-error-list=all --track-origins=yes \
	--log-file=mem_errors.log ./a.out
clean:
	rm ./a.out
