#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ---------------- Temperature Conversion ----------------
// Uses ifs to decide which conversion to make then prints the temperature with the conversion
float temp_convert(char *convert, char *scale, float temp) {
    float new_temp;

    // Find which conversion to make -> if in Celsius and user wants Kelvin converts to Kelvin ect.
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

    // If desired conversion is the same as the current scale -> just returns users temperature
    else {
        new_temp = temp;}
    
    // returns the new temp after conversion
    return new_temp;}

// ---------------- Temperature Category ----------------
// finds what category of weather the users temperature is after converting it to Celsius
char *temp_cat(float temp, char *scale) {
    // If current temp isn't in C converts it to C using temp_converter
    if (strcmp(scale, "C") != 0) {
        temp = temp_convert("C", scale, temp);}
    
    // Creates ranges of temperatures with corresponding weather labels (Hot, cold, freeze, etc)
    if (temp < 0) return "Freezing";
    else if (temp < 10) return "Cold";
    else if (temp < 25) return "Comfortable";
    else if (temp < 35) return "Hot";
    else return "Extreme Heat";}

// ---------------- Weather Advisory ----------------
// Decides what each weather type needs (layers vs jacket)
char *weather(float temp, char *scale) {
    // category depends on the weather found in temp_cat
    char *category = temp_cat(temp, scale);
    // Decides what each weather type needs
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
// runs the functions and prints statements to user
int main() {
    // createsvariables
    float temp;
    char scale[2];
    char convert[2];

    // asks user for temperature
    printf("Enter temperature: ");
    scanf("%f", &temp);

    // Asks for scale and makes users input captal
    printf("Enter scale (C, F, K): ");
    scanf(" %1s", scale);
    scale[0] = toupper(scale[0]);

    // If user input undesired inputs it continues to ask user for input until its acceptable
    while (scale[0] != 'C' && scale[0] != 'F' && scale[0] != 'K') {
        printf("Invalid scale. Enter C, F, or K: ");
        scanf(" %1s", scale);
        scale[0] = toupper(scale[0]);}

    // Find scale user wants to convert to
    printf("Enter scale you wish to convert to (C, F, K): ");
    scanf(" %1s", convert);
    convert[0] = toupper(convert[0]);

    // If scale entered by user is not acceptable, continues to ask for input until it is
    while (convert[0] != 'C' && convert[0] != 'F' && convert[0] != 'K') {
        printf("Invalid scale. Enter C, F, or K: ");
        scanf(" %1s", convert);
        convert[0] = toupper(convert[0]);}

    // assignes new variables based on functions
    float converted = temp_convert(convert, scale, temp);
    char *category = temp_cat(temp, scale);
    char *advice = weather(temp, scale);

    printf("\nConverted temperature: %.2f %s\n", converted, convert); // print converted temp to user
    printf("Temperature category: %s\n", category); // print temp category
    printf("Weather advisory: %s\n", advice); // print advice

    return 0;} // ends program