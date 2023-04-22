/* 
./bin/LinkAlarm --link https://www.youtube.com --hour 5 --minute 24 --pm
*/

#include "include/utils.h"
#include <string.h>

int main(int argc, char *argv[])
{
    bool linkOpen = false;

    if (checkArgs(argc, argv) != 0) return 1;
    printf("No arg identifier erros!\n");

    char *link = argv[2];
    int hours = atoi(argv[4]);
    int minutes = atoi(argv[6]);
    bool isAM = strcmp(argv[7], "--am") == 0 ? true : false;

    if (validTime(hours, minutes) != 0) return 1;
    printf("This link: %s, will open at %d:%d %s\n", link, hours, minutes, isAM ? "AM" : "PM");

    while (!linkOpen) {
        // Get Current Time
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        int currentHour = tm->tm_hour;
        int currentMin = tm->tm_min;
        
        // isAM decides weather or not to add 12 to the hours
        if (isAM) 
        {
            if (hours == currentHour && minutes == currentMin)
            {
                if (openBrowser(link) != 0)
                {
                    printf("Error opening link: %s\n", link);
                    linkOpen = true;
                }
                else
                {
                    printf("Link opened: %s\n", link);
                    linkOpen = true;
                }  
            }
        } 
        else 
        {
            if (hours + 12 == currentHour && minutes == currentMin)
            {
                if (openBrowser(link) != 0)
                {
                    printf("Error opening link: %s\n", link);
                    linkOpen = true;
                }
                else
                {
                    printf("Link opened: %s\n", link);
                    linkOpen = true;
                }      
            }
        }
    }

    printf("Exiting...\n");
    return 0;
}