#ifndef header
#define header
#include <stdio.h>
#include <stdlib.h>

//declaring all the necessary global variables
char array[10][10], p1[20], p2[20]; 
int playernumber, player1dice, player2dice, i, j, empty = 250, ladder = 186, snake = 245, start = 175;
int row = 10, col = 10, counter1 = 0, counter2 = 0;

void init(){                                            //The function that intializes the game determining who starts the game
    switch(playernumber){                               //Switch accepts playernumber as a single expression
        case 1:                                         //If the playernumber is equal to 1
            player1dice = rollDice();                   //Player 1 rolls the dice
            printf("\n%s rolled a %d\n", p1, player1dice);  //The user is informed regarding the dice value they have rolled
            printf("\n%s's turn to roll! Enter player number to roll the dice: ", p2); //Player 2 is encouraged to roll the dice for their turn
            scanf("%d", &playernumber);                 //The input is stored to the adress of the variable named playernumber

            if(playernumber == 2){              //If the player number is equal to 2
                player2dice = rollDice();       //Player 2 rolls the dice
                printf("\n%s rolled a %d\n", p2, player2dice);} //The user is informed regarding the dice value they have rolled
                while(player1dice == player2dice){  //As long as the values both players have rolled are equal to each other
                    printf("\nBoth of you rolled the same, rolling again...\n"); //Both players are informed that another rolling has initialized automatically
                    player1dice = rollDice();   //The dice number rolled for player1 is stored in the variable called 'player1dice'
                    player2dice = rollDice();   //The dice number rolled for player2 is stored in the variable called 'player2dice'
                    printf("\n%s rolled a %d \n", p1, player1dice);     //Player 1 is informed regarding the dice value they have rolled
                    printf("\n%s rolled a %d \n", p2, player2dice);}    //Player2 is informed regarding the dice value they have rolled
            break;
        case 2:
            player2dice = rollDice();       //Player 2 rolls the dice
            printf("\n%s rolled a %d\n", p2, player2dice);  //The user is informed regarding the dice value they have rolled
            printf("\n%s's turn to roll! Enter player number to roll the dice: ", p1);  //Player 1 is encouraged to roll the dice for their turn
            scanf("%d", &playernumber);     //The input is stored to the adress of the variable named playernumber
            if(playernumber == 1){          //If the playernumber is equal to 1
                player1dice = rollDice();   //Player 1 rolls the dice
                printf("\n%s rolled a %d\n", p1, player1dice);} //The user is informed regarding the dice value they have rolled
                while(player1dice == player2dice){  //As long as the values both players have rolled are equal to each other
                    printf("\nBoth of you rolled the same, rolling again...\n");    //Both players are informed that another rolling has initialized automatically
                    player1dice = rollDice();   //The dice number rolled for player1 is stored in the variable called 'player1dice'
                    player2dice = rollDice();   //The dice number rolled for player2 is stored in the variable called 'player2dice'
                    printf("\ns rolled a %d \n", p1, player1dice);  //Player 1 is informed regarding the dice value they have rolled
                    printf("\ns rolled a %d \n", p2, player2dice);} //Player2 is informed regarding the dice value they have rolled
            break;
        default:
            printf("Wrong player number, start the game again");}   //If the player number is inappropriate, the user is informed reagrding the matter
    if(player1dice>player2dice){                //If player 1 has rolled a greater value than player 2
        printf("\n%s rolls first!\n", p1);      //Then player 1 is informed
    }else if(player2dice>player1dice){          //If player 2 has rolled a greater value than player 1
        printf("\n%s rolls first!\n", p2);}}    //Then player 2 is informed
int rollDice(void){     //The function used to roll the dice
    int n;              //Declaring a necessary local variable
    n = rand() % ((6+1)-1)+1;
    return n;}
int printGrid(void){    //The function used to print the grid
    int x,y, row = 10, col = 10;        //Declaring all the necessary local variables
    for (x = 0; x < row; x++) {         //For every row
        for (y = 0; y < col; y++) {     //For every column
            printf("%c", array[x][y]);}     //Print every element of the array
        printf("\n");}}                 //Print a new line after every row
int loop(){                         //The function that is called within main the while loop allowing the players to roll dice respectively
    printf("\nEnter player number to roll the dice: "); //The user is informed when they need to roll the dice
    scanf("%d", &playernumber);     //The input is stored to the adress of the variable 'playernumber'
    if(playernumber == 1){          //Checking if the playernumber is 1
        player1dice = rollDice();   //Player 1 rolls the dice, the value is stored in the variable called 'player1dice'
        printf("\n%s rolled %d\n", p1, player1dice);    //Player 1 is informed about the value they have rolled
        counter1 += 1;              //The variable called 'counter1' counts the number of time player 1 rolls the dice
        return 1;}                
    else if(playernumber == 2){     //Checking if the player number is 2  
        player2dice = rollDice();   //Player 2 rolls the dice, the value is stored in the variable called 'player2dice'
        printf("\n%s rolled %d\n", p2, player2dice);    //Player 2 is informed about the value they have rolled
        counter2 += 1;              //The variable called 'counter2' counts the number of time player 2 rolls the dice
        return 0;}}
int generateGrid(){                 //The function used to generate the grid
    for (i = 0; i < row; i++) {     
        for (j = 0; j < col; j++) {
            if (j == 3 && (i == 2 || i == 3 || i== 4 || i == 5 || i == 6 || i ==7)){
                array[i][j] = ladder; //Locating the ladder
            }else if((i == 4 && j == 9) || (i == 5 && j == 8) || (i == 6 && j == 7) || (i == 7 && j == 6) || (i == 8 && j == 5)){
                array[i][j] = snake; //Locating the snake
            }else if((i == 0 && j == 0) || i == 9 && j == 9){
                array[i][j] = start;} //Locating the start and end characters
            else{
                array[i][j] = empty;}}}} //Locating the empty characters
#endif