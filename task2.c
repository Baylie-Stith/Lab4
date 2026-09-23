#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ---------------- Temperature Conversion ----------------

float temp_convert(char *convert, char *scale, float temp) {
    float new_temp;

    if (strcmp(convert, "K") == 0 && strcmp(scale, "C") == 0) {
        new_temp = temp + 273.15;}

    else if (strcmp(convert, "C") == 0 && strcmp(scale, "K") == 0) {
        new_temp = temp - 273.15;}

    else if (strcmp(convert, "F") == 0 && strcmp(scale, "K") == 0) {
        new_temp = (temp - 32) * (5.0/9.0) + 273.15;}

    else if (strcmp(convert, "K") == 0 && strcmp(scale, "F") == 0) {
        new_temp = (temp - 273.15) * (9.0/5.0) + 32;}

    else if (strcmp(convert, "C") == 0 && strcmp(scale, "F") == 0) {
        new_temp = (temp * (9.0/5.0)) + 32;}

    else if (strcmp(convert, "F") == 0 && strcmp(scale, "C") == 0) {
        new_temp = (temp - 32) * (5.0/9.0);}

    else {
        new_temp = temp;}

    return new_temp;}

// ---------------- Temperature Category ----------------

char *temp_cat(float temp, char *scale) {
    if (strcmp(scale, "C") != 0) {
        temp = temp_convert("C", scale, temp);}

    if (temp < 0) return "Freezing";
    else if (temp < 10) return "Cold";
    else if (temp < 25) return "Comfortable";
    else if (temp < 35) return "Hot";
    else return "Extreme Heat";}

// ---------------- Weather Advisory ----------------

char *weather(float temp, char *scale) {
    char *category = temp_cat(temp, scale);

    if (strcmp(category, "Freezing") == 0)
        return "Bundle up! Beware frostbite!";
    else if (strcmp(category, "Cold") == 0)
        return "Wear layers!";
    else if (strcmp(category, "Comfortable") == 0)
        return "Take a jacket just in case!";
    else if (strcmp(category, "Hot") == 0)
        return "Drink water and wear less!";
    else
        return "DO NOT GO OUTSIDE! IT IS HOOTTTT!";}

// ---------------- Main Program ----------------

int main() {
    float temp;
    char scale[2];
    char convert[2];

    printf("Enter temperature: ");
    scanf("%f", &temp);

    // Read scale
    printf("Enter scale (C, F, K): ");
    scanf(" %1s", scale);
    scale[0] = toupper(scale[0]);

    // Validate scale
    while (scale[0] != 'C' && scale[0] != 'F' && scale[0] != 'K') {
        printf("Invalid scale. Enter C, F, or K: ");
        scanf(" %1s", scale);
        scale[0] = toupper(scale[0]);
    }

    // Read convert-to scale
    printf("Enter scale you wish to convert to (C, F, K): ");
    scanf(" %1s", convert);
    convert[0] = toupper(convert[0]);

    // Validate convert
    while (convert[0] != 'C' && convert[0] != 'F' && convert[0] != 'K') {
        printf("Invalid scale. Enter C, F, or K: ");
        scanf(" %1s", convert);
        convert[0] = toupper(convert[0]);
    }

    float converted = temp_convert(convert, scale, temp);
    char *category = temp_cat(temp, scale);
    char *advice = weather(temp, scale);

    printf("\nConverted temperature: %.2f %s\n", converted, convert);
    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advice);

    return 0;}