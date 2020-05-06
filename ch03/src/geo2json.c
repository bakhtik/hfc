/* convert comma-separated data to JSON format */

#include <stdio.h>

#define false 0;
#define true 1;



int main()
{
    float latitude;
    float longitude;
    char info[80];
    int started = false;

    puts("data=[ ");
    while (scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3) {
        if (started)
            printf(",\n");
        else
            started = true;

        if ((latitude < -90) || (latitude > 90)) {
            fprintf(stderr, "invalid latitude: %f\n", latitude);
            return 2;
        } else if ((longitude < -180) || (longitude > 180)) {
            fprintf(stderr, "invalid longitude: %f\n", longitude);
            return 2;
        }

        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    puts("\n]");

    return 0;
}
