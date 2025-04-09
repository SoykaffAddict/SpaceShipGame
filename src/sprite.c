#include "sprite.h"
#include <raylib.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#define FULLPATH_S 1000
static int compare (const void * a, const void * b );
static const char *GetFilenameExt(const char *filename);

Sprite *CreateSprite(int frames_n, float *dt) 
{
	Texture2D *textures = malloc(sizeof(Texture2D) * frames_n);
	Sprite *sp1 = malloc(sizeof(Sprite));
	*sp1 = (Sprite) {
		.frames_n = frames_n,
		.actual_f = 0,
		.speed = 0,
		.dt = dt,
		.textures = textures,
	};

	return sp1;
}

void LoadSpriteFromDir(Sprite *s, char *dir)
{
	struct dirent *de;

	DIR *dr = opendir(dir);

	if (dr == NULL) {
		printf("Could not open current directory" );
		exit(EXIT_FAILURE);
	}

	char *dir_strings[20];
	int files_read = 0;
	char img_ext[] = "png";
	while ((de = readdir(dr)) != NULL) {
		if (strcmp(GetFilenameExt(de->d_name), img_ext) == 0) {
			dir_strings[files_read] = de->d_name;
			files_read++;
		} else {
			printf("%s is not a png, skipping...\n", de->d_name);
		}
	}

	qsort(dir_strings, files_read, sizeof(char *), compare);

	for (int i = 0; i < files_read; i++) {
		char fullpath[FULLPATH_S+1] = "\0";
		snprintf(fullpath, FULLPATH_S, "%s/%s", dir, dir_strings[i]);
		s->textures[i] = LoadTexture(fullpath);
	}

	closedir(dr);
}

static const char *GetFilenameExt(const char *filename) {
	const char *dot = strrchr(filename, '.');
	if(!dot || dot == filename) return "";
	return dot + 1;
}

static int compare (const void * a, const void * b ) {
  return strcmp(*(char **)a, *(char **)b);
}
