#include <stdio.h>

// runs entire program which prints all possible combonation of user inputted score
int main() {
    int score; // creates score variable as an int

    // while loop that continuously calculates possible score until user enters 1
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): "); // Asks user for score

        // find if user inputs a string
        int result = scanf("%d", &score);
        // Handle non-numeric input
        if (result != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear bad input
            while (getchar() != '\n');
            continue;}

        // exits program when 1 inputted
        if (score == 1) {
            printf("Program terminated.\n");
            break;}

        // Handle negative or zero scores
        if (score <= 0) {
            printf("Score must be a positive integer.\n");
            continue;}

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

            // prints possible combinations
            printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

            // Loop through every possible number of TD + 2pt plays (worth 8 points each)
            for (int td2 = 0; td2 <= score / 8; td2++) 
                // Loop through every possible number of TD + FG plays (worth 7 points each)
                for (int tdfg = 0; tdfg <= score / 7; tdfg++) {
                    // Loop through every possible number of regular touchdowns (worth 6 points each)
                    for (int td = 0; td <= score / 6; td++) {
                        // Loop through every possible number of field goals (worth 3 points each)
                        for (int fg = 0; fg <= score / 3; fg++) {
                            // Loop through every possible number of safeties (worth 2 points each)
                            for (int s = 0; s <= score / 2; s++) {
                                // Calculate the total score for this combination of plays
                                int total = td2 * 8 + tdfg * 7 + td * 6 + fg * 3 + s * 2;

                                // If the total matches the user's score, print the combination
                                if (total == score) {
                                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                        td2, tdfg, td, fg, s);}}}}}}

        return 0;} // ends program
