#include "include/utils.h"
#include <string.h>

int checkArgs(int argc, char *argv[])
{
    char *usage = "Usage: ./LinkAlarm --link <link> --hour <hour> --minute <minute> --<pm/am>";

    int linkCheck = strcmp(argv[1], "--link");
    int hourCheck = strcmp(argv[3], "--hour");
    int minuteCheck = strcmp(argv[5], "--minute");

    if (argc != MAX_ARGS || linkCheck != 0 || hourCheck != 0 || minuteCheck != 0)
    {
    if (strcmp(argv[7], "--am") != 0 || strcmp(argv[7], "--pm") != 0) {
            printf("%s\n", usage);
            return 1;
        }
    }

    return 0;
}

int validTime(int hours, int minutes)
{
    if (hours < 0 || hours > 12 || minutes < 0 || minutes > 59)
    {
        printf("Invalid time!\n");
        return 1;
    }

    return 0;
}

int openBrowser(char *link)
{
    char *cmd = malloc(strlen("open ") + strlen(link) + 1);
    if (cmd == NULL) {
        printf("Error: failed to allocate memory\n");
        return 1;
    }
    strcpy(cmd, "open ");
    strcat(cmd, link);

    system(cmd);
    free(cmd);

    return 0;
}   