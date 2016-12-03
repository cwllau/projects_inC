#include <stdio.h>
#include "cwllau_hangperson.h"

main () {
    char player1[SIZE];
    char player2_wrong[MAX_TIMES];
    char player2_correct[SIZE];
    char faces[FACE_HEIGHT][FACE_WIDTH];
    
    player2_wrong[0] = '\0'; 
    
    int guesses_left = MAX_TIMES;
    int str_length = 0;
    int num_of_letters = 0;
    int spaces = 0;
    int won = 0;
    
    int counter;
   
    get_phrase(player1, player2_correct, &str_length);
    
    for (counter = 1; counter <= str_length; counter++) {
            if (player1[counter - 1] == ' ') {
                spaces++;
            }
    }
    
    num_of_letters = str_length - spaces;
    
    for (counter = 1; counter <= HIDE_INPUT_SPACE; counter++) {
        printf("\n");
    }

    while (guesses_left > 0 && guesses_left <= 6 && won == 0) { 
        
        draw_picture(guesses_left, faces);
        
        print_display(faces, num_of_letters, player2_correct, player2_wrong, guesses_left);
        
        guess_phrase(player1, &guesses_left, player2_wrong, player2_correct, str_length);
        
        won = won_or_continue(player1, player2_correct, str_length);
    }
    
    if (won == 1) { 
        print_display(faces, num_of_letters, player2_correct, player2_wrong, guesses_left);
        printf("YOU WON! Winner winner chicken dinner!\n");
        printf("The phrase was: %s\n", player1);
    } else if (won == 0) { //6 incorrect guesses
        draw_picture(guesses_left, faces);
        print_display(faces, num_of_letters, player2_correct, player2_wrong, guesses_left);
        printf("Game over!\n");
        printf("The phrase was: %s\n", player1);
    }
}