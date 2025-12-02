/**********************************************************************************************************************
Program...........: Math Tutor V6
Programmers.......: Ben Stearns, Javion Wilkins
Date..............: 11-21-25
Section...........: Section 3 – 12:00 pm
GitHub Repo.......: https://github.com/bstearns07/MathTutorV6
Description.......: The purpose of this program is to:
                        - Display a fun welcome banner with funny math jokes
                        - Ask for the user's name and greet them
                        - Use random generation to produce a math problem for the user to solve
                        - Give the user 3 attempts to answer the question correctly
                        - Asks if the user wishes to continue after each question
                        - Levels up to harder problems after 3 correct answers
                        - Levels down to easier problems after 3 incorrect answers if applicable
                        - Validates that answers are numeric and if user enters a valid wish to continue
                        - Uses vectors to store statistics on each question asked
                        - When the player is done playing, a final report is generated with the following:
                            - Displays how the player did on each question
                            - Displays total number of question correct, incorrect, and % correct
                        - Necessary program functions are encapsulated into separate header and definition files
                        - (new) Support for saving and loading game progress
                            - (new) Saving/Loading game progress is validated through try/catch logic
File Description...: defines the main function to run the application
***********************************************************************************************************************/

//import necessary code for the file
#include <cstdlib>      //used to add random numbers
#include <ctime>        //to allow for the use of the time() function for random seeding
#include <iostream>     //used to allow for console input, output, and left/right alignment
#include <windows.h>    //to use SetConsoleOutputCP() to set console output to UTF-8 for better ascii art support
                        //so the dog avatar can have a smiley face "‿"
#include <vector>       //to allow us to use vectors
#include <iomanip>      //to allow use setw() operations
#include "mathtutor.h"  //to import the functions required for the app to run
#include <stdexcept>
using namespace std;    //so fully-qualified statements aren't needed for cout's and cin's

//Begin main function of the program
int main() {
    //necessary variables for program operation
    vector<vector<int> > allQuestions;          //This is for the 2D vector
    string username                     = "?";  //stores user's name
    string userInput                    = "?";  //for asking if the user wishes to continue
    int totalCorrect                    = 0;    //keeps track of how many questions the user got correct
    int totalIncorrect                  = 0;    //keeps track of how many question the user got incorrect
    int mathLevel                       = 1;    //current difficulty level
    bool isCorrect = false;                     //for storing whether the user got a question right or wrong
    SetConsoleOutputCP(CP_UTF8);     //sets the console output code page to UTF-8 for better ascii art
    srand(time(0));                        //seeds random number generation using the system clock time


    //Display Game's Intro
    DisplayGameIntro();

    //ask for the user's name, store the response, and greet them
    username = GetUsersName();

    //check if save data exists. If so, ask if the user wishes to load the data or start a new game. If yes, load data
    //catch any runtime errors that occur
    try {
        mathLevel = LoadPreviousGame(username, allQuestions);
    }
    catch(runtime_error& e) {
        cout<< endl;
        cout<<e.what()<<endl;
    }

    //keep generating and asking user math questions while they wish to continue with the program as a do/while loop
    do {
        //generate a random math question based on the user's mathLevel and store as a vector
        vector<int> currentQuestion;
        try {
            currentQuestion = GenerateRandomQuestion(mathLevel);
        }
        catch(runtime_error& except) {
            cout<< endl;
            cout<< except.what()<<endl;
            return -1;
        }
        //give the user up to 3 attempts to answer the random question. Store whether they got it right or wrong
        isCorrect = GiveThreeAttempts(username, currentQuestion);

        //if user got the question correct, increment totalCorrect by 1. Otherwise, increment totalIncorrect by 1
        if (isCorrect)
            totalCorrect++;
        else
            totalIncorrect++;

        //add the current question to the 2d vector
        allQuestions.push_back(currentQuestion);

        //check whether the user is eligible to level up or down and perform the associated logic
        CheckForLevelChange(totalCorrect, totalIncorrect, mathLevel);
        getline(cin, userInput); // clears the new line from the input buffer

        //ask if the user wants to continue and store their input
        userInput = YesNoQuestion(username + ", do you want to continue? (y=yes | n=no): ");

    } while (userInput == "yes" || userInput == "y");
    //end of do/while loop for user's wish to continue with the program

    //use the 2d vector to display the final summary report
    DisplaySummaryReport(allQuestions);
    try {
        SaveCurrentGame(username, allQuestions);
    }
    catch (runtime_error &e) {
        cout<< endl << e.what() << endl;
    }

    //say goodbye to the user
    cout << R"(
                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V)" << endl;
    cout << "[Digit:] Thanks for playing the silly simple math tutor " << username << "!" << endl;

    //end program by returning 0
    return 0;
}