#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ARGS 8

int checkArgs(int argc, char *argv[]);
int validTime(int hours, int minutes);
int openBrowser(char *link);

#endif