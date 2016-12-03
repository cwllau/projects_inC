void get_phrase(char input[SIZE], char correct[SIZE], int* length) {
    int counter = 1;
    
    printf("Please enter a phrase of 50 characters or less:     (Game is case-sensitive)\n");
    scanf("%[^\n]s", input);
    
    while (counter <= SIZE && input[counter - 1] != '\0') {
        //if not a null character, update length
        *length = *length + 1;
        counter++; 
    }
    
    for (counter = 1; counter <= *length; counter++) {
        if (input[counter - 1] != ' ') {
            correct[counter - 1] = '_';
            correct[counter] = '\0'; 
        } else {
            correct[counter - 1] = ' ';
            correct[counter] = '\0';
        }
    }
}

void guess_phrase(char input[SIZE], int* tries_left, char wrong[MAX_TIMES], char right[SIZE], int length) {
    int counter = 1;
    int found_flag = 0;
    char letter;
    
    printf("Enter a letter to guess the phrase:     (entering the same wrong letter multiple times counts as multiple incorrect guesses)\n");
    scanf(" %c", &letter);

    //check
    found_flag = check(input, letter, length); 
        
    if (found_flag == 1) {  //if found, find all instances of guessed letter and fill in the blanks
        fill_in_correct(input, length, right, letter); 
        
    } else if (found_flag == 0) {   //if not found, store this to memory and display to player2
        *tries_left = *tries_left - 1;
        wrong_guesses(*tries_left, wrong, letter);
    }
}

int check(char input[SIZE], char letter, int length) {
    int counter;
    int found_flag = 0;
    
    for (counter = 1; counter <= length; counter++) { 
        if (letter == input[counter - 1]) {
            found_flag = 1;
            break; 
        } else if (letter != input[counter - 1]) {
            found_flag = 0;
        }

    }
    
    return found_flag;
}

void fill_in_correct(char input[SIZE], int length, char right[SIZE], char letter) {
    int counter;
    
    for (counter = 1; counter <= length; counter++) {
            if(input[counter - 1] == letter) {
                right[counter - 1] = letter; 
            }
    }
}

void wrong_guesses(int remaining_tries, char wrong[MAX_TIMES], char letter) { 
    int nth_wrong_guess; 
    
    nth_wrong_guess = MAX_TIMES - remaining_tries;
    
    
    
    wrong[nth_wrong_guess - 1] = letter;
    wrong[nth_wrong_guess] = '\0'; 
}

int won_or_continue(char input[SIZE], char correct[SIZE], int length) {
    int counter;
    int matching;
    
    //check each letter of each string
    for (counter = 1; counter <= length; counter++) {
        if (correct[counter - 1] == input[counter - 1]) {
            matching = 1;
        } else if (correct[counter - 1] != input[counter - 1]) {
            matching = 0;
            break; 
        }
    }
    
    return matching;
}

void draw_picture(int tries_left, char pic[][FACE_WIDTH]) {
    int row_index;
    int column_index; 
    char open_mouth = 'O';
    char gasp = 'A';
    
    for (row_index = 0; row_index < FACE_HEIGHT; row_index++) {
        for (column_index = 0; column_index < FACE_WIDTH; column_index++) {
            
            if (row_index == 0) { 
                pic[row_index][column_index] = TOP_BOTTOM;
                
                if (column_index == 0 || column_index == FACE_WIDTH - 1) {
                    pic[row_index][column_index] = ' ';
                }
                
            } else if (row_index != 0) {
                if (column_index == 0 || column_index == FACE_WIDTH - 1) {
                    pic[row_index][column_index] = RIGHT_LEFT;
                    
                } 
                else if (column_index != 0) {
                    pic[row_index][column_index] = ' '; //populate with spaces first
                    
                    if (row_index == FACE_HEIGHT - 1 && (column_index > 0 && column_index < FACE_WIDTH - 1)) { //then REPLACE those spaces with TOP_BOTTOM
                        pic[row_index][column_index] = TOP_BOTTOM;

                    }
                    
                    if (row_index == 1) {
                        if (tries_left == 3 || tries_left == 4) {
                            if (column_index == 2) {
                                pic[row_index][column_index] = '/';
                            }
                            if (column_index == 10) {
                                pic[row_index][column_index] = '\\';
                            }
                        }
                    }
                    
                    
                    if (row_index == 2 && (column_index == 3 || column_index == 9)) { 
                        if (tries_left >= 3 && tries_left <= 6) {
                            pic[row_index][column_index] = EYE;
                        } else if (tries_left == 1 || tries_left == 2) {
                            pic[row_index][column_index] = SURPRISED_EYE;
                        } else if (tries_left == 0) {
                            pic[row_index][column_index] = GAME_OVER_EYE;
                        }
                    }
                    
                    if (row_index == 4) {
                        if (tries_left == 6) {
                            pic[row_index][4] = '\\';
                            pic[row_index][8] = '/';
                            
                            if (column_index > 4 && column_index < 8) { 
                                pic[row_index][column_index] = '_';
                            }
                        } else if (tries_left == 5) {
                            if (column_index >= 4 && column_index <= 8) {
                                pic[row_index][column_index] = '_';
                            }
                        } else if (tries_left == 4) {
                            pic[row_index][6] = open_mouth;
                        } else if (tries_left == 3) {
                            pic[row_index][5] = '/';
                            pic[row_index][6] = '\\';
                        } else if (tries_left == 2) {
                            if (column_index >= 4 && column_index <= 8) {
                                pic[row_index][column_index] = '_';
                            }
                        } else if (tries_left == 1) {
                            pic[row_index][6] = gasp;
                        } else if (tries_left == 0) {
                            pic[row_index][6] = open_mouth;
                        }
                    }
                    
                } 
                
            }
                
        }
    }

}

void print_display(char pic[][FACE_WIDTH], int num_of_letters, char correct[SIZE], char wrong[SIZE], int tries_left) {
    int row_i;
    int column_i;
    
    printf("\n\n\n\n");
    
    for (row_i = 0; row_i < FACE_HEIGHT; row_i++) {
        for (column_i = 0; column_i < FACE_WIDTH; column_i++) {
            printf("%c", pic[row_i][column_i]);
        }
        printf("\n");
    }
        
        printf("\nCharacters (without spaces): %d\n", num_of_letters); 
        printf("%s\n\n", correct);
        printf("Incorrect guesses: %s\n", wrong); 
        printf("Guesses left: %d\n\n", tries_left);
}


