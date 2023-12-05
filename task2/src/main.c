#include <stdio.h>

struct Game {
    int id;
    int red;
    int blue;
    int green;
};

int main() {
    // store the results from each game
    struct Game game_list[100];

    // Reading in the datafile
    char line[200];
    FILE *file = fopen("data/aoc_task2.txt", "r");
    if (file == NULL){
        printf("error opening the file");
        return 1;
    }
    while(fgets(line, sizeof(line), file) != NULL){
        // Sort the input string
        printf("%s", line);
        // Get game ID
        line_array = input_string.split(":")

    }

    // Sort the input string
    
    

    for i

    fclose(file);

    return 0;
}


