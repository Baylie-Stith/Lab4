#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);

        if (score == 1) {
            printf("Program terminated.\n");
            break;}

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

        for (int td2 = 0; td2 <= score / 8; td2++) {          // TD + 2pt (8)
            for (int tdfg = 0; tdfg <= score / 7; tdfg++) {   // TD + FG (7)
                for (int td = 0; td <= score / 6; td++) {     // TD (6)
                    for (int fg = 0; fg <= score / 3; fg++) { // FG (3)
                        for (int s = 0; s <= score / 2; s++) { // Safety (2)

                            int total = td2 * 8 + tdfg * 7 + td * 6 + fg * 3 + s * 2;

                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       td2, tdfg, td, fg, s);}}}}}}}
    return 0;}