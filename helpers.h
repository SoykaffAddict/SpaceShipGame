#ifndef SPACESHIP_HELPER
#define SPACESHIP_HELPER

#ifdef _WIN32
	#define OS_SEP "\\" //Filesytem separator for compatibility
#elif __linux__
	#define OS_SEP "/" //Filesytem separator for compatibility
#endif

/***********************************************************
* Join: joins listed folder strings with the OS separator, *
        this was inspired by the function of the same name *
        on python. The pointer must be freed.              *
***********************************************************/
char *Join(int argc, ...);

#endif
