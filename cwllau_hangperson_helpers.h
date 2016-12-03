void get_phrase(char input[SIZE], char correct[SIZE], int* length);
void guess_phrase(char input[SIZE], int* tries_left, char wrong[MAX_TIMES], char right[SIZE], int length);
int check(char input[SIZE], char letter, int length);
void fill_in_correct(char input[SIZE], int length, char right[SIZE], char letter);
void wrong_guesses(int remaining_tries, char wrong[MAX_TIMES], char letter);
int won_or_continue(char input[SIZE], char correct[SIZE], int length);
void draw_picture(int tries_left, char pic[][FACE_WIDTH]);
void print_display(char pic[][FACE_WIDTH], int num_of_letters, char correct[SIZE], char wrong[SIZE], int tries_left);