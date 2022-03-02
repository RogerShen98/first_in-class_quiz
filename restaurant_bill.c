/* 
CS2600 First In Class Quiz
Liangjie Shen
2/3/2022

This program that computes the tax and tip on a restaurant bill for a patron. 
The program should accept the tax and tip both as percentages from the 
command line when running the program. Meaning as argument passed into the 
main(). Display the meal cost, tax amount, tip amount, and total bill on 
the screen. The meal cost should be randomly chosen between the following 
four:
Salad: $9.95
Soup: $4.55
Sandwich: $13.25
Pizza: $22.35

Note: The input arguments are already in percentage form.

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
        
        double meal_price = price[chosen_meal_index];
        double tax_amount = meal_price*(atof(argv[1])/100);
        double tip_amount = meal_price*(atof(argv[2])/100);
        // atof changes string to float number

        printf("Tax Amount: $%.2f",tax_amount);
        printf("(%s%%)\n",argv[1]);
        printf("Tip Amount: $%.2f",tip_amount);
        printf("(%s%%)\n",argv[2]);
        printf("Total Bill: $%.2f\n",meal_price+tax_amount+tip_amount);

    }
    
    return 0;
}