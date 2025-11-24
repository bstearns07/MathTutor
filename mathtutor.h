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
File Description...: defines the function prototypes required for the application
***********************************************************************************************************************/

#ifndef MATHTUTOR_H
#define MATHTUTOR_H

#include <string>
#include <vector>
using namespace std;

/**
 * @brief Outputs the game's intro screen as cout's
 *
 * This function prints the game's intro to the output screen
 *
 * @return void
 */
// define function prototypes
void DisplayGameIntro();

/**
 * @brief Prompts the user for their name and greets them.
 *
 * This function asks the user to enter their name, stores it in a string,
 * and then prints a personalized greeting along with an ASCII art dog.
 *
 * @return string: The username entered by the user.
 */
string GetUsersName();

/**
 * @brief Creates a math question using random generation
 *
 * This uses random number generation and a random enum for math symbol via switch statement
 * to generate a random math question
 *
 * @return vector<int> A vector containing the information for the random math question
 */
vector<int> GenerateRandomQuestion(int mathLevel);

/**
 * @brief Validates that whatever is in the input buffer is a numeric value
 *
 * This function tests that whatever is in the input buffer is a numeric value only.
 * If the input buffer doesn't contain a numeric value, loops the user to keep trying
 * until a valid number is detected.
 *
 * @return int: The user's answer to a question
 */
int GetNumericValue();

/**
 * @brief Gives the user attempts at answering a random question
 *
 * This function utilizes a for loop to give the user up to 3 attempts at answering a question
 * Also appends the number of attempts it took to the end of the question's vector
 *
 * @return bool: Whether the user got the question right or wrong
 */
bool GiveThreeAttempts(string username, vector<int> &currentQuestion);

/**
 * @brief Determines whether the user is eligible for leveling up or down
 *
 * This function utilizes pass-by-reference to determine if user got 3 answers right/wrong
 * If so, this function performs the logic of increasing/decreasing the user's math level
 *
 * @return void
 */
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel);

/**
 * @brief Asks the user a yes/no question (such as wish to continue or save/load game)
 *
 * Asks the user to enter y/yes or n/no to a question
 * Validates that y/yes or n/no is typed
 *
 * @return string: Whether the user's answer to a question as ' "y/yes/n/no"
 */
string YesNoQuestion(string question);

/**
 * @brief Prints the final summary report for the user's time spent playing
 *
 * This function parses a 2D vector of all questions the user was asked and
 * produces a summary report to print to the screen
 *
 * @return void
 */
void DisplaySummaryReport(const vector<vector<int> > &allQuestions);

void SaveCurentGame(string username, const vector<vector<int> > &allQuestions);

int LoadPreviousGame(string username, vector<vector<int>>&allQuestions);
#endif //MATHTUTOR_H
