/* 
CS2600 First In Class Quiz
Liangjie Shen
2/3/2022

This program creates an interactive program that allows a user to 
guess a number between 1-10. You should create a menu that will have 
options (this should be displayed on the screen):
	Press 1 to play a game
	Press 2 to change the max number
	Press 3 to quit

If option 1 is selected the program should prompt the user to enter a number. 
If the user is correct tell them they won then the program should go back 
to the menu. Otherwise tell them if they were too low or high in there guess and 
allow them to guess again. This should continue until they win. If they enter q 
instead of a number when prompted the game should end(NOT the program) and return to 
the menu.

If option 2 is chosen, then tell them the max value they can set the number. 
Make sure they do not enter a negative number or go above the max value.

If option 3 is chosen complete the following three:
thank the user for playing, 
print out the result of all the games played. Number of guesses required to win. 
NOTE: They could quit a game if this occurs indicate game was lost. 
end the game.

Finally create a new branch – call it save_user_max_number
	
Save the users request for the max number in which the program can remember 
the max number from the previous time
NOTE: This is called persists, meaning we can recall data after process is stopped

*/


#include <stdio.h> // input/output library
#include <stdlib.h> // atof fucntion and random number generator
#include <time.h> // time variable 
#include <string.h> // string library
#include <ctype.h> // type check
#include <stdbool.h> // Header-file for boolean data-type.

// function declaration
void guessNumber(int max);
int changeMax();

// global variable
int guessCount = 0;
int finalResult = 0;

int main()
{
    int option = 0;
    int max = 10;
    int counter = 0;
    int result[100];
    int guess[100];

    // end the game if the user pressed 3
    while(option!=3){
        
        // welcome message and user input
        printf("\n\nWelcome to the Number Guessing Game!\n"
        "\nPress 1 to play a game"
        "\nPress 2 to change the max number"
        "\nPress 3 to quit\n\n");

        // get user input for the menu
        
        scanf("%d",&option);

        while(option!= 1&&option!=2&&option!=3){
            printf("Not Valid Input! Please try again!\n");
            scanf("%d",&option);
        }

        if(option==1){
            guessNumber(max);
            result[counter] = finalResult; // store the win or lose condition each game
            guess[counter] = guessCount; // store the guess number each game
            counter++; // increment
            guessCount = 0;
        }

        else if(option==2){
            max = changeMax();
        }

        else{
            printf("Thanks for playing!\n");
            for(int i = 0; i < counter; i++){
                if(result[i]==1)
                    printf("Game %d: win\n",i+1);
                
                else    
                    printf("Game %d: lose\n",i+1);

                printf("Number of guesses: %d\n\n", guess[i]);
            }

        }
    }

    return 0;
    
}

void guessNumber(int max){
    // random number between 1-10
    int randomNum = 0;
    char inputString[100];
    time_t t; // initialize time variable

    // random number generator
    srand((unsigned) time(&t)); 

    if(max == 10)
        // random a number from 1-10
        randomNum = rand() % 10 + 1;

    else
        // random a number from 0-max
        randomNum =  rand() % max;

    char randomStr[100];
    sprintf(randomStr, "%d", randomNum);

    printf("Pick a number between 1-%d[enter q to go back to the menu]: ", max);

    while(strcmp(randomStr,inputString)!=0){

        scanf("%s",inputString);

        if(strcmp(inputString,"q")==0){
            finalResult = 0;
            break; // lose the game
        }
        

        else if(randomNum < atoi(inputString)){
            printf("Number too high!\n");
            guessCount++;
        }

        else if(randomNum > atoi(inputString)){
        
            printf("Number too low!\n");
            guessCount++;
        }

        else if(strcmp(randomStr,inputString)==0){
            printf("Congrats! You got the number right!\n");
            finalResult = 1;
            break; // wins the game
        }

        else
            printf("Wrong input!\n");


    }


}

int changeMax(){
    int max = -1;

    while(max<0||max>1000){
        printf("What maximum number do you want it to be?"
        "[Positive Only and less than 1000]: ");
        scanf("%d",&max);

        if(max<0||max>1000)
            printf("Wrong number input");
        
    }

    printf("\nMax Number Changed...\n");

    // store max number in save_user_max_number.txt file i.e. persist
    FILE *fp;

    fp = fopen("save_user_max_number.txt", "w+");
    fprintf(fp,"Max Number: %i",max);
    fclose(fp);

    return max;
}
