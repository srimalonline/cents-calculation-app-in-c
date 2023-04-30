#include <stdio.h>
#include <string.h>

// define constants for coin values and array size
#define FIFTY 50
#define TWENTY 20
#define TEN 10
#define FIVE 5
#define SIZE 100

// declare global variables for storing customer data and coin counts
char first[SIZE]; // array for first name initials
char last[SIZE]; // array for last name initials
int cents[SIZE]; // array for number of cents
int fifty[SIZE]; // array for number of fifty cent coins
int twenty[SIZE]; // array for number of twenty cent coins
int ten[SIZE]; // array for number of ten cent coins
int five[SIZE]; // array for number of five cent coins
int count = 0; // variable for counting the number of customers
char choice = '1'; // initialize it to 1 to enter the loop

// declare functions for menu, input, output, calculation and search
void menu();
void input();
void output(int index);
void calculate(int index);
int search(char f, char l);

// main function
int main()
{
    // loop until the user enters 0 to exit
    while (choice != 'n')
    {
        // display the menu and get the user choice
        menu();
        int valid = 0; // flag variable to indicate validity of input
        while (!valid) // loop until valid input is entered
        {
            scanf(" %c", &choice);
            if (choice == '1' || choice =='2') // check if choice is in range
            {
                valid = 1; // set the flag to true if input is valid
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
                printf("Enter your choice:");
                while (getchar() != '\n'); // clear the input buffer
            }
        }

        // if the user enters 1, call the input and output functions
        if (choice == '1')
        {
            input();
            output(count - 1); // use count - 1 as the index because count has been incremented by one in the input function
        }
        // if the user enters 2, call the search function and display the result
        else if (choice == '2')
        {
            char f, l;
            printf("Enter initials of first name: ");
            scanf(" %c", &f); // use a space before %c to skip whitespace characters
            printf("Enter initials of last name: ");
            scanf(" %c", &l); // use a space before %c to skip whitespace characters
            int index = search(f, l);
            if (index == -1)
            {
                printf("No record found.\n");
            }
            else
            {
                output(index);
            }
        }

        // ask the user if they want to continue
        printf("Do you wish to continue calculating change? (y/n):");
        valid = 0; // reset the flag variable
        while (!valid) // loop until valid input is entered
        {
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'n') // check if choice is 0 or 1
            {
                valid = 1; // set the flag to true if input is valid
                if(choice == 'y') // continue loop if your enter 'y'
                {
                    continue;
                }
                else if(choice == 'n') // break loop if you enter 'n'
                {
                    break;
                }
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
                printf("Do you wish to continue calculating change? (y/n):");
                while (getchar() != '\n'); // clear the input buffer
            }
        }
    }

    // exit the program with a message
    printf("Thank you !\n");
    return 0;
}

// menu function to display the options and prompt the user to enter a choice
void menu()
{
    printf("\nPress 1 to enter customer's data\n");
    printf("Press 2 to search for customer's record\n");
    printf("Enter your choice: ");
}

// input function to get the customer's data and store it in arrays
void input()
{
    printf("Enter initials of first name: ");
    scanf(" %c", &first[count]); // use a space before %c to skip whitespace characters

    // get the last name initial and store it in the last array at the current index
    printf("Enter initials of last name: ");
    scanf(" %c", &last[count]);

    // get the number of cents and validate it to be in range and multiple of 5
    int valid = 0; // flag variable to indicate validity of input
    while (!valid) // loop until valid input is entered
    {
        printf("Enter number of cents as a whole number: ");
        scanf("%d", &cents[count]);
        if (cents[count] >= 5 && cents[count] <= 95 && cents[count] % 5 == 0)
        {
            valid = 1; // set the flag to true if input is valid
        }
        else
        {   
            printf("Invalid input. Please enter a number between 5 and 95 that is a multiple of 5.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }
    }

    // call the calculate function to compute the coin counts and store them in arrays at the current index
    calculate(count);

    // increment the count variable by one to move to the next index
    count++;

}

// search function to find the index of a customer by their initials
int search(char f, char l)
{
    // loop through the first and last arrays and compare the initials with the parameters
    for (int i = 0; i < count; i++)
    {
        if (first[i] == f && last[i] == l)
        {
            return i; // return the index if a match is found
        }
    }
    return -1; // return -1 if no match is found
}

// output function to display the customer's data and coin counts
void output(int index)
{
    // print the initials and number of cents
    printf("Initials of first name: %c\n", first[index]);
    printf("Initials of last name: %c\n", last[index]);
    printf("Number of cents: %d\n", cents[index]);

    // print the coin counts with a table format
    printf("NUMBER OF EACH DENOMINATION:\n");
    printf("==========================\n");
    printf("%d x fifty cent piece(s)\n", fifty[index]);
    printf("%d x twenty cent piece(s)\n", twenty[index]);
    printf("%d x ten cent piece(s)\n", ten[index]);
    printf("%d x five cent piece(s)\n", five[index]);
    printf("==========================\n");
    printf("Total: %d cents\n", cents[index]);
    printf("==========================\n");
}

// calculate function to compute the coin counts for a given number of cents
void calculate(int index)
{
    // initialize the coin counts to zero
    fifty[index] = 0;
    twenty[index] = 0;
    ten[index] = 0;
    five[index] = 0;

    // use a local variable to store the number of cents and leave the cents array unchanged
    int amount = cents[index];

    // use a loop to subtract the coin values from the amount until it becomes zero
    while (amount > 0)
    {
        // if the amount is greater than or equal to 50, subtract 50 and increase the fifty count by one
        if (amount >= FIFTY)
        {
            amount -= FIFTY;
            fifty[index]++;
        }
        // else if the amount is greater than or equal to 20, subtract 20 and increase the twenty count by one
        else if (amount >= TWENTY)
        {
            amount -= TWENTY;
            twenty[index]++;
        }
        // else if the amount is greater than or equal to 10, subtract 10 and increase the ten count by one
        else if (amount >= TEN)
        {
            amount -= TEN;
            ten[index]++;
        }
        // else if the amount is greater than or equal to 5, subtract 5 and increase the five count by one
        else if (amount >= FIVE)
        {
            amount -= FIVE;
            five[index]++;
        }
    }
}