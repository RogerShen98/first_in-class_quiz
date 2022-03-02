Restaurant Bill 
Write a program that computes the tax and tip on a restaurant bill for a patron. The program should accept the tax and tip both as percentages from the command line when running the program. Meaning as argument passed into the main(). Display the meal cost, tax amount, tip amount, and total bill on the screen. The meal cost should be randomly chosen between the following four:
Salad: $9.95
Soup: $4.55
Sandwich: $13.25
Pizza: $22.35



Number guessing game 
Create an interactive program that allows a user to guess a number between 1-10. You should create a menu that will have options (this should be displayed on the screen):
	Press 1 to play a game
	Press 2 to change the max number
	Press 3 to quit

If option 1 is selected the program should prompt the user to enter a number. 
If the user is correct tell them they won then the program should go back to the menu. Otherwise tell them if they were too low or high in there guess and allow them to guess again. This should continue until they win. If they enter q instead of a number when prompted the game should end(NOT the program) and return to the menu.

If option 2 is chosen, then tell them the max value they can set the number. Make sure they do not enter a negative number or go above the max value.

If option 3 is chosen complete the following three:
thank the user for playing, 
print out the result of all the games played. Number of guesses required to win. 
NOTE: They could quit a game if this occurs indicate game was lost. 
end the game.

Finally create a new branch – call it save_user_max_number
	
Save the users request for the max number in which the program can remember the max number from the previous time
	NOTE: This is called persists, meaning we can recall data after process is stopped
