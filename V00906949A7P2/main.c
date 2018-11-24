/*
Name: Ezra Nestel
UVicID: V00906949
Date: 2018/11/22
Assignment: Assignment 7, Part 2
File name: V00906949A7P2.c
Description: Converts roman numeral to integers
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define FILE_NAME "TourismInVictoria.html"
#define GMAPS_KEY "AIzaSyC_24ju4UlYCEwn3EdRn4uc3KKUkTNuk2g"
#define MAP_WIDTH "900"
#define MAP_HEIGHT "900"
#define MAP_CENTER "Victoria,Canada"
#define MAP_ZOOM "12"

/**
 * The struct that represents a Marker in the map.
 */
typedef struct{
    int id;
    char color[10];
    char label[30];
    float latitude;
    float longitude;
} Marker;

char* concat(const char *s1, const char *s2);
char* formatMarker (char* color, char* label, char* latitude, char* longitude);
char* formatUrl (char* center, char* zoom, char* mapWidth, char* mapHeight);
char** str_split(char* a_str, const char a_delim);
char* completeURL(char* baseUrl, char* color, char* label, char* latitude, char* longitud);
char* formatReadMarker(Marker m);
char* readFromConsole(int num);
char* obtainMapUrl(char* center, char* zoom, char* mapWidth, char* mapHeight, char* markers);
char* replace_char(char* str, char find, char replace);
void writeHtml(char* filename, char* markers, char* mapUrl);
int main();

/**
 * Allows to create formatted string from a marker. The string uses this format: markerColor/markerLabel/markerLatitude/markerLongitude.
 *
 * @param m The marker from which the string will be generated.
 * @return A formatted string from a marker. The string uses this format: markerColor/markerLabel/markerLatitude/markerLongitude.
 */
char* formatReadMarker(Marker m) {

    char* text = NULL;
    sprintf(text,"%s/%s/%f/%f",m.color,m.label,m.latitude,m.longitude );
    return text; // replace with your code
}

/**
 * Allows to concat two strings.
 *
 * @param s1 The first string to concat.
 * @param s2 The second string to concat.
 * @return The result of the concat operation.
 */
char* concat(const char *s1, const char *s2)
{

    char* newString = NULL;
    sprintf(newString, "%s%s",s1,s2);
    return ""; // replace with your code
}

/**
 * Allows to generate a proper format for a marker.
 *
 * @param color The color of the marker in the map.
 * @param label The label of the marker in the map.
 * @param latitude The latitude of the marker in the map.
 * @param longitude The longitude of the marker in the map.
 * @return A format required by the GMaps API.
 * @author lfrivera
 */
char* formatMarker (char* color, char* label, char* latitude, char* longitude) {

    char* colorConcat = concat("&markers=color:",color);

    char* labelMetaConcat = concat(colorConcat,"%%7Clabel:");
    free(colorConcat);

    char* labelConcat = concat(labelMetaConcat,label);
    free(labelMetaConcat);

    char* latitudeMetaConcat = concat(labelConcat,"%%7C");
    free(labelConcat);

    char* latitudeConcat = concat(latitudeMetaConcat,latitude);
    free(latitudeMetaConcat);

    char* longitudeMetaConcat = concat(latitudeConcat,",");
    free(latitudeConcat);

    char* longitudeConcat = concat(longitudeMetaConcat,longitude);
    free(latitudeMetaConcat);

    return longitudeConcat;
}

/**
 * Allows to format the base of the URL.
 *
 * @param center The centern of the map (e.g., Victoria,BC,British Colombia)
 * @param zoom An integer that determines the zoom of the map (e.g. 13)
 * @param mapWidth An integer that determines the width of the map (e.g. 600)
 * @param mapHeight An integer that determines the height of the map (e.g. 300)
 * @return A format required by the GMaps API.
 * @author lfrivera
 */
char* formatUrl (char* center, char* zoom, char* mapWidth, char* mapHeight) {

    char* centerConcat = concat("https://maps.googleapis.com/maps/api/staticmap?center=",center);

    char* zoomMetaConcat = concat(centerConcat,"&zoom=");
    free(centerConcat);

    char* zoomConcat = concat(zoomMetaConcat,zoom);
    free(zoomMetaConcat);

    char* sizeMetaConcat = concat(zoomConcat,"&size=");
    free(zoomConcat);

    char* sizeWidthConcat = concat(sizeMetaConcat,mapWidth);
    free(sizeMetaConcat);

    char* sizeHeightMetaConcat = concat(sizeWidthConcat,"x");
    free(sizeWidthConcat);

    char* sizeHeightConcat = concat(sizeHeightMetaConcat,mapHeight);
    free(sizeHeightMetaConcat);

    char* mapTypeMetaConcat = concat(sizeHeightConcat,"&maptype=roadmap");
    free(sizeHeightConcat);

    return mapTypeMetaConcat;
}

/**
 * Allows to split a string.
 *
 * @param a_str The string to split.
 * @param a_delim The delimiter.
 * @return The tokens.
 */
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;
    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);
        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}

/**
 * Allows to complete the map's url with a new marker.
 *
 * @param baseUrl The base url to complete.
 * @param color The color of the marker.
 * @param label The label used for the marker.
 * @param latitude The latitude of the marker.
 * @param longitude The longitude of the marker.
 * @return A new version of the map's url that includes a new marker.
 * @author lfrivera
 */
char* completeURL(char* baseUrl, char* color, char* label, char* latitude, char* longitude) {
    char* markersConcat = concat(baseUrl,"&markers=");

    char* colorMetaConcat = concat(markersConcat,"color:");
    free(markersConcat);

    char* colorConcat = concat(colorMetaConcat,color);
    free(colorMetaConcat);

    char* labelMetaConcat = concat(colorConcat,"%7Clabel:");
    free(colorConcat);

    char* labelConcat = concat(labelMetaConcat,label);
    free(labelMetaConcat);

    char* latitudeMetaConcat = concat(labelConcat,"%7C");
    free(labelConcat);

    char* latitudeConcat = concat(latitudeMetaConcat,latitude);
    free(latitudeMetaConcat);

    char* longitudeMetaConcat = concat(latitudeConcat,",");
    free(latitudeConcat);

    char* longitudeConcat = concat(longitudeMetaConcat,longitude);
    free(longitudeMetaConcat);

    return longitudeConcat;
}

/**
 * Allows to read the markers from the console using a csv format.
 *
 * @param num The number of times to read from the console.
 * @return A string with the following format: marker1Color/marker1Label/marker1Latitude/marker1Longitude_marker2Color/marker2Label/marker2Latitude/marker2Longitude
 */
char* readFromConsole(int num) {
    char* tmp;
    //Using the struct
    Marker m;
    bool firstTime = true;

    for(int i = 0 ; i < num ; i++) {
        printf("%s\n","Please enter a tourist attraction in Victoria using the following format: id,markerColor,markerLabel,latitude,longitude\nExample: 1,blue,Royal+British+Columbia+Museum,48.419472,-123.367589");
        int result = scanf("%i,%[^,],%[^,],%f,%f", &m.id, m.color, m.label, &m.latitude, &m.longitude);

        if(result != 5) {
            printf("Invalid input!\n");
        } else {

            char* formattedMarker = formatReadMarker(m);
            if(firstTime) {
                tmp = formattedMarker;
                firstTime = false;
            } else {
                tmp = concat(tmp,"_");
                tmp = concat(tmp,formattedMarker);
            }
        }
    }
    return tmp;
}


/**
 * Allows to obtain a map that includes markers.
 *
 * @param center  The center (location) of the map (e.g., Victoria,Canada).
 * @param zoom  The zoom of the map (e.g., 13).
 * @param mapWidth The width of the map (e.g., 600)
 * @param mapHeight The width of the map (e.g., 300)
 * @param markers A string that contains the markers to include in the map. The following format must be used: marker1Color/marker1Label/marker1Latitude/marker1Longitude_marker2Color/marker2Label/marker2Latitude/marker2Longitude
 * @author lfrivera
 */
char* obtainMapUrl(char* center, char* zoom, char* mapWidth, char* mapHeight, char* markers) {
    char* baseUrl = formatUrl(center,zoom,mapWidth,mapHeight);
    char* partialUrl = baseUrl;
    char** markerTokens;
    markerTokens = str_split(markers, '_');

    if (markerTokens)
    {
        int i;
        for (i = 0; *(markerTokens + i); i++)
        {
            char* markerToken = *(markerTokens + i);

            char color[100];
            char label[100];
            char latitude[100];
            char longitude[100];

            char** tokens;
            tokens = str_split(markerToken, '/');

            if (tokens)
            {
                int j;
                for (j = 0; *(tokens + j); j++)
                {
                    char* token = *(tokens + j);

                    if(j == 0) {
                        memset(color, '\0', sizeof(color));
                        strcpy(color,token);
                    }

                    if(j == 1) {

                        memset(label, '\0', sizeof(label));
                        strcpy(label,token);
                    }

                    if(j == 2) {
                        memset(latitude, '\0', sizeof(latitude));
                        strcpy(latitude,token);
                    }

                    if(j == 3) {
                        memset(longitude, '\0', sizeof(longitude));
                        strcpy(longitude,token);
                    }
                }

                free(tokens);
            }
            partialUrl = completeURL(partialUrl,color,label,latitude,longitude);
            free(*(markerTokens + i));
        }
        free(markerTokens);
    }
    char* tmpFullUrl = concat(partialUrl,"&key=");
    char* fullUrl = concat(tmpFullUrl,GMAPS_KEY);
    free(tmpFullUrl);

    return fullUrl;
}

/**
 * Allows to replace a character in a string.
 *
 * @param str The string.
 * @param find The character to find.
 * @param replace The character to replace.
 * @return A new string without a specific character.
 */
char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos){
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}

/**
 * Allows to create a new HTML page that includes a map with the markers read from the .csv file.
 *
 * @param filename The name of the file.
 * @param markers The formatted markers obtained from the .csv file.
 * @param mapUrl The map url.
 * @author lfrivera
 */
void writeHtml(char* filename, char* markers, char* mapUrl) {
    FILE * fp = fopen(filename, "w");

    fprintf(fp, "<html>\n");
    fprintf(fp, "<body>\n");
    fprintf(fp, "<h1>Popular Tourist Attractions in Victoria!</h1>\n");
    fprintf(fp, "<img src=\"");
    fprintf(fp,"%s",mapUrl);
    fprintf(fp,"\" ");
    fprintf(fp,"width=\"");
    fprintf(fp,MAP_WIDTH);
    fprintf(fp,"\" ");
    fprintf(fp,"height=\"");
    fprintf(fp,MAP_HEIGHT);
    fprintf(fp,"\">\n");
    fprintf(fp,"<ul>\n");

    char** markerTokens;
    markerTokens = str_split(markers, '_');

    if (markerTokens)
    {
        int i;
        for (i = 0; *(markerTokens + i); i++)
        {
            char* markerToken = *(markerTokens + i);
            char color[100];
            char label[100];

            char** tokens;
            tokens = str_split(markerToken, '/');

            if (tokens)
            {
                int j;
                for (j = 0; *(tokens + j); j++)
                {
                    char* token = *(tokens + j);
                    if(j == 0) {
                        memset(color, '\0', sizeof(color));
                        strcpy(color,token);
                    }
                    if(j == 1) {
                        memset(label, '\0', sizeof(label));
                        strcpy(label, token);
                    }
                }
                free(tokens);
            }
            fprintf(fp,"<li>");
            fprintf(fp, "%s", color);
            fprintf(fp,": ");
            fprintf(fp, "%s", replace_char(label,'+',' '));
            fprintf(fp,"</li>\n");

            free(*(markerTokens + i));
        }
        free(markerTokens);
    }
    fprintf(fp,"</ul>\n");
    fprintf(fp, "</body>\n");
    fprintf(fp, "</html>\n");

    fclose(fp);
}


int main() {
    char* markers;

    printf("%s\n","Please enter the number of tourist attractions you want to show in the map (e.g., 1):");
    int num;
    fflush(stdout);
    int result = scanf("%i", &num);

    if(result != 1) {
        printf("Invalid input!\n");
        return EXIT_FAILURE;
    } else {

        markers  = readFromConsole(num);
    }

    char markersCopy[1000];
    strcpy(markersCopy, markers);

    char* mapUrl = obtainMapUrl(MAP_CENTER,MAP_ZOOM,MAP_WIDTH,MAP_HEIGHT,markers);
    writeHtml(FILE_NAME, markersCopy,mapUrl);
    printf("The HTML file %s has been generated successfully!\n", FILE_NAME);
    return EXIT_SUCCESS;
}