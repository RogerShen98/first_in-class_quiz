/* 
CS2600 First In Class Quiz
Liangjie Shen
2/3/2022

*/
#include <stdio.h> // input/output library
#include <stdlib.h> // atof fucntion and random number generator
#include <time.h> // time variable 

int main(int argc, char* argv[])
{
    // welcome message and user input
    printf("Welcome to the Restauratn Bill Calculator!\n"
        "Please enter tax and tip on a restaurant bill for a patron"
        "in this form: ./restaurant_bill.out [tax:0-50] [tip:>=0]\n"
        "NOTE: tax and tip are automatically put as percentage\n");


    // if the arguments from the user input is not 3, redo the process again
    if(argc != 3) { 
        printf("Wrong form, please enter in this form:"
        " ./restaurant_bill.out [tax:0-50] [tip:>=0]\n");
    }


    else{
        // show the menu
        printf("\nHere is the menu:\n"
        "Salad: $9.95\n"
        "Soup: $4.55\n"
        "Sandwich: $13.25\n"
        "Pizza: $22.35\n");

        char *meal[4] = {"Salad", "Soup", "Sandwich", "Pizza"};
        double price[4] = {9.95, 4.55, 13.25, 22.35};

        int chosen_meal_index = 0;
        time_t t; // initialize time variable

        // random number generator
        srand((unsigned) time(&t)); 

        // pick a number from 0 - 3
        chosen_meal_index =  rand() % 4;

        // Display the meal cost, tax amount, tip amount, 
        // and total bill on the screen.
        printf("\nRandomly Chosen Meal\n%s: $", meal[chosen_meal_index]);
        printf("%.2f\n", price[chosen_meal_index]);
        
        

    }
    
    return 0;
}