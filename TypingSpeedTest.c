#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10
#define WORD_LENGTH 20
#define NAME_LENGTH 30

const char **choose_category();
void play_game();

const char *teachers_words[MAX_WORDS] = {
    "Smruty", "Prashant", "Sarah", "Prabhat", "Shamim",
    "Shehzad", "Vahid", "Sujal", "Madhuvanti", "Rajesh"
};

const char *students_words[MAX_WORDS] = {
    "Irfan", "Prem", "Palash", "Zidane", "Namra",
    "OmSoham", "Sakshi", "Dev", "Aayan", "Saamiya"
};

const char **choose_category() {
    int choice;
    printf("Choose a category:\n1. Teachers\n2. Students\n");
    scanf("%d", &choice);

    if (choice == 1) {
        return teachers_words;
    } else if (choice == 2) {
        return students_words;
    } else {
        printf("Invalid choice. Defaulting to Students.\n");
        return students_words;
    }
}

void play_game() {
    const char **words = choose_category();

    char input[WORD_LENGTH];
    int score = 0;
    time_t start_time, end_time;
    double time_spent;
    char player_name[NAME_LENGTH];

    printf("Enter your name: ");
    scanf("%s", player_name);

    time(&start_time);

    for (int i = 0; i < MAX_WORDS; i++) {
        printf("Type the word: %s\n", words[i]);
        scanf("%s", input);

        if (strcmp(input, words[i]) == 0) {
            score++;
        }
    }

    time(&end_time);
    time_spent = difftime(end_time, start_time);

    printf("\nTime taken by %s: %.2f seconds\n", player_name, time_spent);
    printf("%s Scored: %d/%d\n", player_name, score, MAX_WORDS);

    if (score == 10 && time_spent > 30) {
        printf("You should increase your typing speed.\n");
    } else if (score == 10 && time_spent > 20) {
        printf("Your typing speed is average. You can improve it!\n");
    } else if (score == 10 && time_spent < 20) {
        printf("Your typing speed is too fast! Faster than Flash!\n");
    }
}

int main() {
    char play_again;

    do {
        play_game();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y');

    return 0;
}
