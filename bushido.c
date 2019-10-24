/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+ Program: Bushido
+ Creator: Kevin Ellis
+ Version: 1.0
+ Year: 2019
+ Description: Bushido is a command line math, reading and writing game for kids
\++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ROUNDS 3

void PrintMenu(char **);
void SelectMenu(char *);
float AskMath(void);
float CalcScore(int, int);
void PlayGood(void);
void PlayBad(void);

int main(void)
{
    char *cChoice;

    do{ //main game loop continues to run until user quits
        PrintMenu(&cChoice);
        SelectMenu(cChoice);
    } while (strcmp(cChoice, "0") != 0);

    free(cChoice);

    return 0;
}// end main

void PrintMenu(char **choice)
{
    //print the main menu for the game
    printf("\n[1] Math");
    printf("\n[2] Reading");
    printf("\n[3] Writing");
    printf("\n[0] Quit\n");

    //allocate more memory to choice
    *choice = calloc(20, sizeof(char));

    //if memory allocation was successful
    if(choice)
        gets(*choice);
    else
        printf("\nOut of Memory");

}//end PrintMenu

//void SelectMenu(char choice[])
void SelectMenu(char *choice)
{
    //enters the option that the user selects
        if (strcmp(choice, "1") == 0)
        {
            //user wants to do math
            float fMathScore;
            fMathScore = AskMath();
        }//end if 1
        else if(strcmp(choice, "2") == 0)
        {
            printf("\nReading");
        }//end else if 2
        else if(strcmp(choice, "3") == 0)
        {    
            printf("\nWriting");
        }//end else if 3
        else if(strcmp(choice, "0") == 0)
        {
            printf("\nThanks for playing\nGood Bye!");
        }//end else 0
        else
        {
            printf("\nSorry thats not an option.");
        }//end else incorrect
}//end SelectMenu

float AskMath(void)
{
    //Ask questions about math and return the score
            int iNum1 = 0;
            int iNum2 = 0;
            int a = 0; //placeholder for subtraction converter
            int iOperator;
            int iRounds;
            int iCorrect = 0;
            char cGuess[15] = {'\0'};
            char cAnswer[15] = {'\0'};
            srand(time(NULL));
            
            for (iRounds = 0; iRounds < ROUNDS; ++iRounds) //change this value later after testing
            {
                iNum1 = (rand() % 10) + 1;
                iNum2 = (rand() % 10) + 1;
                iOperator = (rand() % 2) + 1;

                if (iOperator == 1)
                {
                        printf("\n%d + %d = ", iNum1, iNum2);
                        gets(cGuess);
                        sprintf(cAnswer, "%d", (iNum1 + iNum2));

                        if (strcmp(cGuess, cAnswer) == 0)
                        {
                            PlayGood();
                            printf("\nCorrect");
                            ++iCorrect;
                        }//end if correct addition
                        else
                        {
                            PlayBad();
                            printf("\nWrong");
                        }//end else wrong addition
                }//end if addition
                else{
                        if (iNum1 < iNum2)
                        {
                            a = iNum1;
                            iNum1 = iNum2;
                            iNum2 = iNum1;
                        }//end if num1 < num2
                        printf("\n%d - %d = ", iNum1, iNum2);
                        gets(cGuess);
                        sprintf(cAnswer, "%d", (iNum1 - iNum2));
                        if (strcmp(cGuess, cAnswer) == 0)
                        {
                            PlayGood();
                            printf("\nCorrect");
                            ++iCorrect;
                        }//end if correct subtraction
                        else
                        {
                            PlayBad();
                            printf("\nWrong");
                        }//end else wrong subtraction
                }//end else subtraction

                printf("\n\tRound <%d>", iRounds + 1);

            }//end for rounds

            printf("\nYour score was %.2f\%", CalcScore(ROUNDS, iCorrect));
}//end AskMath

float CalcScore(int questions, int correct)
{
    //calculat the score by getting the number correct and amount of questions
    float score;

    if (questions == correct)
    {
        score = 100;
    }
    else if (correct == 0)
    {
        score = 0;
    }
    else
    {
        score = ((float)correct / (float)questions) * 100;
    }
    return score;
}//end CalcScore

void PlayGood(void)
{
    //plays a chime to indicate good job
    system("python C:\\Users\\knell\\OneDrive\\Desktop\\Programs\\C\\Bushido\\resources\\sound.py C:\\Users\\knell\\OneDrive\\Desktop\\Programs\\C\\Bushido\\resources\\good.mp3");
}

void PlayBad(void)
{
    //plays a chime to indicate good job
    system("python C:\\Users\\knell\\OneDrive\\Desktop\\Programs\\C\\Bushido\\resources\\sound.py C:\\Users\\knell\\OneDrive\\Desktop\\Programs\\C\\Bushido\\resources\\bad.mp3");
}