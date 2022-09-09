#include <iostream>
#include <cstdlib>
#include <ctime>


int main();
void game_selection();

//Rock Paper Scissors Functions
int rps_main();
void rps_game_display(std::string name);
int rps_user_selection();
int rps_game_result (int player_choice, int computer_choice);
int rps_computer_selection();

//Tic Tac Toe Functions
int ttt_main();
void ttt_display_board(std::string positions[9]);
std::string ttt_player_counter(int turn);
bool ttt_check_board (std::string positions[9]);
bool ttt_verify_input (int player_input, std::string positions[9]);

//Hangman Functions
int hm_main();
std::string hm_setup();
bool hm_guess_word (std::string user_input, std::string word);
void hm_print_word(std::string word, char correct_letters_guessed []);
std::string hm_random_selector(std::string category[20]);
bool hm_verify_input (std::string input);
bool hm_check_letter (char guess, std::string word);
void hm_print_row (std::string hangman_board_row[5]);
char hm_guess_letter();
void hm_game_over ();

int main() {
    // insert code here...
    game_selection();
    return 0;
}

void game_selection () {
    std::cout << "--------------------------WELCOME TO AKSHAT'S MINI ARCADE--------------------------" << std::endl << std::endl;
    std::cout << "\t \t \t WHAT GAME WOULD YOU LIKE TO PLAY? \t \t \t " << std::endl;
    std::cout << "\t \t \t 1. ROCK-PAPER-SCISSORS \t \t \t " << std::endl;
    std::cout << "\t \t \t 2. TIC-TAC-TOE \t \t \t " << std::endl;
    std::cout << "\t \t \t 3. HANGMAN \t \t \t " << std::endl;
    std::cout << "\t \t \t 4. EXIT \t \t \t " << std::endl;
    std::cout << std::endl;
    int input {};
    std::cout << "Game Number: ";
    std::cin >> input;
//    while (input != 1 || input != 2 || input != 3 ) {
//        std::cout << "Game Number: ";
//        std::cin >> input;
//    }
    switch(input) {
        case 1:
            rps_main();
            break;
        case 2:
            ttt_main();
            break;
        case 3:
            hm_main();
            break;
        case 4:
            exit(0);
            
    }
    
}

// Rock Paper Scissors

int rps_main () {
    
    while (true) {
        //Instructions for game
        std::cout << "Welcome to Rock-Paper-Scissors! ";
        std::cout << "To remind you how to play, you will chose either Rock (1), Paper (2), or Scissors (3)" << std::endl;
        std::cout << "Then, the computer will also choose one of them and whomever has the \"stronger\" will win in a best of three!" << std::endl;
        std::cout << "Rock crushes scissors, scissors cut paper, and paper covers rock."<< std::endl;
        std::cout << std::endl;
        int user_input = rps_user_selection();
        int computer_input = rps_computer_selection();
        std::string objects[3] = {"Rock", "Paper", "Scissors"};
        std::string results[3] = {"You win! Congrats! ", "It is a draw! ", "You lost! "};
         //need to add delay
        rps_game_display("ROCK");
        rps_game_display("PAPER");
        rps_game_display("SCISSORS");
        rps_game_display("SHOOT");
        // need to fix selection
        std::cout << "You selected " << objects[user_input] << " ,and the computer selected " << objects[computer_input] << std::endl;
        int result = rps_game_result(user_input, computer_input);
        std::cout << results[result];
        std::string play_again{};
        std::cout << "Would you like to play again? Yes (Y) or No (N): ";
        std::cin >> play_again;
        while (true)
        if (play_again == "Y") {
            continue;
        } else if (play_again == "N") {
            main();
            // break;
        } else {
            std::cout << "Please enter a valid input: ";
            std::cin >> play_again;
        }
    }
    
};

int rps_user_selection () {
    int user_input{};
    std::cout << "What would you like to select player? Rock (0), Paper (1), or Scissors (2):  ";
    std::cin >> user_input;
    while (true) {
         if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cout<<"Invalid input, please try again: ";
            std::cin >> user_input;
        }
        if (!std::cin.fail()) {
            if (!(user_input > 0) && !(user_input < 2) ) {
                continue;
            } else {
                return user_input;
            }
        }
    }
}

void rps_game_display (std::string name) {
    std::cout << name << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

int rps_game_result (int player_choice, int computer_choice) {
    //need to return more better result
    if ( ( (player_choice == 0) && (computer_choice == 2) ) || ( (player_choice == 1) && (computer_choice == 0) ) || ( (player_choice == 2) && (computer_choice == 1) ) ){
        return 0;
    } else if (player_choice == computer_choice) {
        return 1;
    } else {
        return 2;
    }
    return 0;
}

int rps_computer_selection () {
    srand((unsigned) time(0));
    int computer_choice = (rand() % (2-0+1));
    return computer_choice;
}

// Rock Paper Scissors



// Tic Tac Toe
int ttt_main () {
    
    while (true) {
        //Instructions for game
        std::cout << "Welcome to Tic-Tac-Toe! "<< std::endl;
        std::cout << "To remind you how to play, two players (Player 0 and Player X) will take turns putting their marks in empty squares within a 3x3 grid. " << std::endl;
        std::cout << "The first player to get 3 of their marks in a row wins!" << std::endl;
        std::cout << std::endl;
        std::string positions[9] {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        int turn{5};
        
        for (int i {0}; i <= 9; ++i) {
            std::string player_playing = ttt_player_counter(turn);
            ttt_display_board(positions);
            std::cout << std::endl;
            int player_input{};
            std::cout << "Player " + player_playing + ", it is your turn! On which position would you like to place your marker: ";
            std::cin >> player_input;
            bool input_check = ttt_verify_input(player_input, positions);
            while (input_check == false) {
                std::cin >> player_input;
                bool input_check_2 = ttt_verify_input(player_input, positions);
                if (input_check_2 == true) {
                    break;
                }
                
            };
            positions[player_input-1] = player_playing;
            turn++;
            bool win = ttt_check_board(positions);
            if (win == true) {
                std::cout<< "Player " + player_playing + " has won the game, congrats!"<< std::endl;
                ttt_display_board(positions);
                break;
            } else if ((win == false) && (i == 8)) {
                std::cout << "The game has ended in a draw."<< std::endl;
                break;
            } else {
                continue;
            }
        };
        
        
        std::string play_again{};
        std::cout << "Would you like to play again? Yes (Y) or No (N): ";
        std::cin >> play_again;
        // while (true)
        if (play_again == "Y") {
            continue;
        } else if (play_again == "N") {
            main();
        } else {
            std::cout << "Please enter a valid input: ";
            std::cin >> play_again;
        }
    }
    
};

bool ttt_verify_input (int player_input, std::string positions[9] ) {
    bool proper_input{false};
    while ((player_input >= 1) && (player_input <= 9)) {
        while (positions[player_input-1] == "O" || positions[player_input-1] == "X") {
            std::cout << "There is already a marker there, please choose another marker: ";
            return proper_input;
        };
        proper_input = true;
        return proper_input;
    };
    std::cout << "That number is not in the range, please choose another marker: ";
    return proper_input;
}

bool ttt_check_board (std::string positions[9]) {
    if (positions[0] == positions[1] && positions[1] == positions[2]) {
        return true;
    } else if (positions[3] == positions[4] && positions[4] == positions[5]) {
        return true;
    } else if (positions[6] == positions[7] && positions[7] == positions[8]) {
        return true;
    } else if (positions[0] == positions[3] && positions[3] == positions[6]) {
        return true;
    } else if (positions[1] == positions[4] && positions[4] == positions[7]) {
        return true;
    } else if (positions[2] == positions[5] && positions[5] == positions[8]) {
        return true;
    } else if (positions[0] == positions[4] && positions[4] == positions[8]) {
        return true;
    } else if (positions[2] == positions[4] && positions[4] == positions[6]) {
        return true;
    } else {
        return false;
    }
    
}

void ttt_display_board (std::string positions[9]) {
    std::cout << " " + positions[0] + " | " + positions[1]  + " | " + positions[2] + " " << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " + positions[3] + " | " + positions[4]  + " | " + positions[5] + " " << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " + positions[6] + " | " + positions[7]  + " | " + positions[8] + " " << std::endl;
}

std::string ttt_player_counter (int turn) {
    std::string player_name{};
    if (turn % 2 == 0) {
        player_name = "O";
    } else {
        player_name = "X";
    }
    return player_name;
}

// Tic Tac Toe

// Hangman

int hm_main();
std::string hm_setup();
bool hm_guess_word (std::string user_input, std::string word);
void hm_print_word(std::string word, char correct_letters_guessed []);
std::string hm_random_selector(std::string category[20]);
bool hm_verify_input (std::string input);
bool hm_check_letter (char guess, std::string word);
void hm_print_row (std::string hangman_board_row[5]);
char hm_guess_letter();
void hm_game_over ();


int hm_main() {
    std::string player_word = hm_setup();
    std::string hangman_board_row_1[5] { "-", "-", "-", "-", "+"};
    std::string hangman_board_row_2[5] { " ", " ", " ", " ", "|"};
    std::string hangman_board_row_3[5] { " ", " ", " ", " ", "|"};
    std::string hangman_board_row_4[5] { " ", " ", " ", " ", "|"};
    std::string hangman_board_row_5[5] { " ", " ", " ", " ", "|"};
    int turn{0};
    char letters_guessed[27] {};
    int correct_guesses{0};
    int incorrect_guesses{0};
    char* correct_letters_guessed = new char[player_word.size()] {};
    hm_print_word(player_word, correct_letters_guessed);
    
    while (true) {
        std::cout << std::endl;
        std::cout << std::endl;
        hm_print_row(hangman_board_row_1);
        hm_print_row(hangman_board_row_2);
        hm_print_row(hangman_board_row_3);
        hm_print_row(hangman_board_row_4);
        hm_print_row(hangman_board_row_5);
        std::string guesssing_word{};
        std::string full_word_guess{};
        std::cout << "Would you like to guess the word? Yes (Y) or No (N): ";
        std::cin >> guesssing_word;
        bool verified_input_1 = hm_verify_input(guesssing_word);
        if (guesssing_word == "Y") {
            std::cout << "What do you think the word is: ";
            std::cin >> full_word_guess;
            bool final_guess = hm_guess_word(full_word_guess, player_word);
            if (final_guess == true) {
                std::cout << "You guessed correctly and saved your hangman, the word was: " << player_word << std::endl;
                hm_game_over();
            } else {
                std::cout << "You guessed incorrectly and lose the game! The word was: " << player_word << std::endl;
                hm_game_over();
            }
        } else if (guesssing_word == "N") {
        }
        char guess = hm_guess_letter();
        for (int i{0}; i < sizeof(letters_guessed); ++i) {
                while (letters_guessed[i] == guess) {
                    std::cout << "You have already guessed that letter, try again: ";
                    guess = hm_guess_letter();
                }
        }
        letters_guessed[turn] = guess;
        bool checked_letter = hm_check_letter(guess, player_word);
        if (checked_letter == true) {
            correct_guesses++;
            for (int i{0}; i < correct_guesses; ++i) {
                correct_letters_guessed[turn] = guess;
            }
            hm_print_word(player_word, correct_letters_guessed);
            // continue;
        } else {
            incorrect_guesses++;
            hm_print_word(player_word, correct_letters_guessed);
            if (incorrect_guesses == 1) {
                hangman_board_row_2[1] = "h";
            } else if (incorrect_guesses == 2) {
                hangman_board_row_3[0] = "a";
            } else if (incorrect_guesses == 3) {
                hangman_board_row_3[1] = "n";
            } else if (incorrect_guesses == 4) {
                hangman_board_row_3[2] = "g";
            } else if (incorrect_guesses == 5) {
                hangman_board_row_4[1] = "m";
            } else if (incorrect_guesses == 6) {
                hangman_board_row_5[0] = "a";
            } else if (incorrect_guesses == 7) {
                hangman_board_row_5[2] = "n";
                // game over
                // reveal word
                hm_game_over();
            }
        }
        if (correct_guesses == player_word.size()) {
            //game over
            std::cout << "You guessed correctly and saved your hangman, the word was: " << player_word << std::endl;
            hm_game_over();
        }
        std::cout << std::endl;
        std::cout << "Letter's guessed:";
        for (int i{0}; i < sizeof(letters_guessed); ++i) {
            if (*letters_guessed != '\0') {
                std::cout << letters_guessed[i];
                std::cout << ", ";
            } else {
                continue;
            }
        }
        turn++;
        std::cout << std::endl;
    }
    
    return 0;
};

// chooses from 5 different categories: countries, foods, sports, brands, animals

std::string hm_setup() {
    std::string countries[20] {"Canada", "United States", "Mexico", "Argentina", "Chile", "Brazil", "Germany", "United Kingdom",
    "France", "Italy", "Spain", "Nigeria", "South Africa", "India", "China", "Japan", "Pakistan", "Singapore", "Australia", "New Zealand"};
    std::string foods[20] {"Pasta", "Pizza", "French Fries", "Tacos", "Sushi", "Ceasar Salad", "BLT Sandwich", "Poutine",
    "Mac and Cheese", "Apple Pie", "Steak", "Doughnuts", "Hot Wings", "Hot Dog", "Cheesecake", "Chicken Nuggets", "Hamburger",
    "Ice Cream", "Lasagna", "Milkshake"};
    std::string sports[20] {"Football", "Basketball", "Baseball", "Badminton", "Boxing", "Soccer", "Squash", "Tennis", "Golf", "Ice Hockey",
    "Volleyball", "Golf", "Swimming", "Cricket", "Rugby", "Snowboarding", "Skiing", "Pickleball", "Rowing", "Cycling"};
    std::string brands[20] {"Nike", "Adidas", "Versace", "Audi", "Mercedes Benz", "Apple", "Instagram", "Nestle", "Disney",
    "Pespi", "Mastercard", "Starbucks", "Gillette", "Red Bull", "Rolling Stone", "Rolex", "Heineken", "FedEx", "Paramount", "Walmart"};
    std::string animals[20] {"Cat", "Dog", "Horse", "Lion", "Monkey", "Hyena", "Jaguar", "Elephant", "Porcupine", "Rabbit", "Brown Bear",
    "Grey Wolf", "Moose", "Giraffe", "Gorilla", "Ladybug", "Dolphin", "Bald Eagle", "Alligator", "Bighorn Sheep"};
    
    std::cout << "Welcome to Hangman! To remind you how to play, you will choose one from the following categories (countries, foods, sports, brands, animals), and the computer will choose a random word from the selected category. \n Then you will have the opportunity to guess individual letters that you think are in the word; if correct, they will appear, else, body parts of the presented stickman will increase. At any point, you can guess what you believe the word, and if correct, you win the game.";
    std::cout << std::endl;
    std::cout << std::endl;
    int user_category_selection{0};
    std::cout << "Which category would you like to play in? Countries (1), Foods (2), Sports (3), Brands (4), Animals (5): ";
    std::string user_word{};
    while (true) {
        std::cin >> user_category_selection;
        if (user_category_selection == 1) {
            user_word = hm_random_selector(countries);
            break;
        } else if (user_category_selection == 2) {
            user_word = hm_random_selector(foods);
            break;
        } else if (user_category_selection == 3) {
            user_word = hm_random_selector(sports);
            break;
        } else if (user_category_selection == 4) {
            user_word = hm_random_selector(brands);
            break;
        } else if (user_category_selection == 5) {
            user_word = hm_random_selector(animals);
            break;
        } else {
            std::cout << "Invalid input, try again: ";
            continue;
        }
    };
    std::cout << std::endl;
    std::cout << std::endl;
    return user_word;
};

std::string hm_random_selector(std::string category[20]) {
    srand((unsigned) time(0));
    int random_word = (rand() % (19+1));
    return category[random_word];
};

bool hm_guess_word (std::string user_input, std::string word) {
    if (user_input == word) {
        return true;
    } else {
        return false;
    }
};

bool hm_verify_input (std::string input) {
    while (true) {
        if (input == "Y") {
            return true;
        } else if (input == "N") {
            return true;
        } else {
            std::cout << "Please enter a valid input: ";
            std::cin >> input;
        }
    }
};


void hm_print_word(std::string word, char correct_letters_guessed[]) {

    for(std::size_t i = 0; i < word.length(); ++i){
        //check if word[i] is in correct_letters
        bool is_in = false;
        std::size_t m = 0;
        while( correct_letters_guessed[m] != '\0'){
            is_in |= (tolower(word[i]) == tolower(correct_letters_guessed[m]));
            ++m;
        }
        if(is_in){
            std::cout << word[i];
        } else{
            std::cout << '*';
        }
    }
};



void hm_print_row (std::string hangman_board_row[5]) {
    for (int i{0}; i < 5; ++i) {
        std::cout << hangman_board_row[i];
        std::cout << " ";
    };
    std::cout << std::endl;
};

char hm_guess_letter() {
    char letter{};
    std::cout << "What letter would you like to guess: ";
    while(true) {
        std::cin >> letter;
        if (isalpha(letter) > 0 ) {
            return letter;
        } else {
        std::cout << "That is not a valid input, please try again: ";
        continue;
    }
    return letter;
    }
};

void hm_game_over () {
    std::string play_again{};
    std::cout << "Would you like to play again? Yes (Y) or No (N): ";
    std::cin >> play_again;
    if (play_again == "Y") {
        main();
    } else if (play_again == "N") {
        main();
    } else {
        std::cout << "Please enter a valid input: ";
        std::cin >> play_again;
    }
}

bool hm_check_letter (char guessed_letter, std::string word) {
    for (int i{0}; i < word.size(); ++i) {
        if (toupper(guessed_letter) == word[i] || tolower(guessed_letter) == word[i]) {
            return true;
        } else {
            continue;
        }
    }
    return false;
};


// Hangman
