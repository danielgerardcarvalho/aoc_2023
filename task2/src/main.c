#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Game {
    int id;
    int red;
    int blue;
    int green;
};

int main() {
    // store the results from each game
    struct Game game_list[100];
    int game_list_count = 0;

    // Reading in the datafile
    char line[200];
    FILE *file = fopen("data/aoc_task2.txt", "r");
    if (file == NULL){
        printf("error opening the file");
        return 1;
    }
    while(fgets(line, sizeof(line), file) != NULL){
        game_list[game_list_count].id = -1;
        game_list[game_list_count].red = -1;
        game_list[game_list_count].blue = -1;
        game_list[game_list_count].green = -1;

        // Sort the input string
        char* prev_word = strtok(line, " ");
        char* word = strtok(NULL, " ");
        while (word != NULL) {
            if (strcmp(prev_word, "Game") == 0){
                int number = atoi(word);
                game_list[game_list_count].id = number;
            }
            else if (strstr(word, "red") != NULL){
                int number = atoi(prev_word);
                if (game_list[game_list_count].red < number){
                    game_list[game_list_count].red = number;
                }
            }
            else if (strstr(word, "blue") != NULL){
                int number = atoi(prev_word);
                if (game_list[game_list_count].blue < number){
                    game_list[game_list_count].blue = number;
                }
            }
            else if (strstr(word, "green") != NULL){
                int number = atoi(prev_word);
                if (game_list[game_list_count].green < number){
                    game_list[game_list_count].green = number;
                }
            }

            prev_word = strtok(NULL, " ");
            word = strtok(NULL, " ");
            
        }
        printf("GAME:\n");
        printf("id: %d\n", game_list[game_list_count].id);
        printf("red: %d\n", game_list[game_list_count].red);
        printf("blue: %d\n", game_list[game_list_count].blue);
        printf("green: %d\n", game_list[game_list_count].green);
        printf("\n");
        game_list_count++;
    }
    fclose(file);

    // Find valid games
    int limit_red = 12;
    int limit_blue = 14;
    int limit_green = 13;

    int valid_games_sum = 0;
    int games_power_sum = 0;
    for (int i = 0; i < game_list_count; i++){
        if (game_list[i].red <= limit_red && game_list[i].blue <= limit_blue && game_list[i].green <= limit_green){
            valid_games_sum += game_list[i].id;
        }
        games_power_sum += (game_list[i].red * game_list[i].green * game_list[i].blue);

    }


    printf("Valid Games: %d\n", valid_games_sum);
    printf("Games Power Sum: %d\n", games_power_sum);

    return 0;
}


