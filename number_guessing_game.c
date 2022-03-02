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
#include<ctype.h> // type check

// function declaration
void guessNumber();

int main()
{
    
        // welcome message and user input
        printf("Welcome to the Number Guessing Game!\n"
        "\nPress 1 to play a game"
        "\nPress 2 to change the max number"
        "\nPress 3 to quit\n\n");

        // get user input for the menu
        int option;
        scanf("%d",&option);

        while(option!= 1&&option!=2&&option!=3){
            printf("Not Valid Input! Please try again!\n");
            scanf("%d",&option);
        }

        if(option==1){
            guessNumber();
        }

        else if(option==2){
            changeMax();
        }

        else{
            endGame();
        }

        return 0;
    
}

void guessNumber(){
    // random number between 1-10
    int randomNum = 0;
    char inputString[100];
    time_t t; // initialize time variable

    // random number generator
    srand((unsigned) time(&t)); 

    // pick a number from 0 - 3
    randomNum =  rand() % 10 + 1;

    char randomStr[100];
    sprintf(randomStr, "%d", randomNum);

    printf("Pick a number between 1-10[enter q to go back to the menu]: ");

    while(strcmp(randomStr,inputString)!=0){

        scanf("%s",inputString);

        if(strcmp(inputString,"q")==0){
            break;
        }

        else if(strcmp(randomStr,inputString)<0){
            printf("Number too high!\n");
        }

        else if(strcmp(randomStr,inputString)>0){
            printf("Number too low!\n");
        }

        else if(strcmp(randomStr,inputString)==0){
            printf("Congrats! You got the number right!\n");
            break;
        }

      
    }



}