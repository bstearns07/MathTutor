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
File Description...: defines the functions required for the application
***********************************************************************************************************************/

//import required code for the file
using namespace std;    //so fully-qualified statements aren't needed for cout's and cin's
#include <cctype>       //to allow for character functions like tolower()
#include <cstdlib>      //used to add random numbers
#include <iomanip>      //to allow use setw() operations
#include <iostream>     //used to allow for console input, output, and left/right alignment
#include <limits>       //to allow validating a user's input as numeric up to the stream limit
#include <string>       //to allow for string use and manipulation
#include <vector>       //to allow the use of vector data containers
#include <fstream>      //to allow for file input/output streams
#include <stdexcept>    //to allow throwing runtime exceptions

//global variables required for some functions to run
const int MAX_ATTEMPTS = 3;
const int LEVEL_RANGE = 10;
const string FILE_NAME = "mathtutor.txt";

/**********************************************************************************************************************
 * Displays the program intro and jokes
 * Returns void
 *********************************************************************************************************************/
void DisplayGameIntro() {
    /*
 output an ascii art title using a raw string literal to ignore escape sequences
 output some funny math jokes
 Introduce Digit the dog
 */
    cout << R"(
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ~___  ___      _   _       _____     _             ~
        ~|  \/  |     | | | |     |_   _|   | |            ~
        ~| .  . | __ _| |_| |__     | |_   _| |_ ___  _ __ ~
        ~| |\/| |/ _` | __| '_ \    | | | | | __/ _ \| '__|~
        ~| |  | | (_| | |_| | | |   | | |_| | || (_) | |   ~
        ~\_|  |_/\__,_|\__|_| |_|   \_/\__,_|\__\___/|_|   ~
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)" << endl;
    cout << "**************************************************************************************\n"
            "*   Welcome to the Silly Simple Math Tutor                                           *\n"
            "*   Fun Math facts:                                                                  *\n"
            "*       - Without Geometry, life is pointless                                        *\n"
            "*       - Why was the = sign so humble? Because it knew it wasn't > or < anyone else *\n"
            "*       - Parallel lines have so much in common. It's too bad they'll never meet     *\n"
            "**************************************************************************************\n";
    return;
} //end of DisplayGameIntro()

/**********************************************************************************************************************
 * Prompt the user for their name, welcome the user, and return the user's name
 * Returns the user's name as a string
 *********************************************************************************************************************/
// function implementations
string GetUsersName() {
    string username = "?";//for storing the user's name

    //ask for the user's name and store the response
    cout << "What is your name? ";
    getline(cin, username);

    //Greet the user using their entered username
    cout << "Welcome " << username << " to the Silly Simple Math Tutor!" << endl;
    cout << R"(
                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V)" << endl;
    cout << "My name is Digit the dog, and I'll be your math tutor!" << endl;

    return username;
}

/**********************************************************************************************************************
 * Defines a function that generates a random math question to ask the user
 * Returns a vector containing the required information for the random question
 *********************************************************************************************************************/
vector<int> GenerateRandomQuestion(int mathLevel) {

    //define enum for what type of math question was generated
    enum MathType { MT_ADDITION = 1, MT_SUBTRACTION = 2, MT_MULTIPLICATION = 3, MT_DIVISION = 4 };

    MathType mathType = MT_ADDITION;        //stores the random math enum generated
    int leftNumber      = 0;                //represents number of the left of the math symbol
    int rightNumber     = 0;                //represents number of the right of the math symbol
    int currentRange    = 10 * mathLevel;   //represents the current range of random number based on the user's level
    char mathSymbol     = '?';              //represents the math symbol for the question (+,-,*,/)
    int correctAnswer   = 0;                //represents the right answer for the question
    int tempNumber      = 0;                //for swapping left and right numbers to avoid negative numbers

    //generate a random number between 1 and the current level's range for right and left numbers
    leftNumber = (rand() % currentRange) + 1;
    rightNumber = (rand() % currentRange) + 1;

    //generate a random number between 1-4
    //use the random number generated to randomly select a math type from the MathType enumeration.
    //Store the result cast to a MathType enumeration object
    mathType = static_cast<MathType>(rand() % 4 + 1);

    //set the math symbol based on the random MathType enumeration that was generated using a switch statement
    switch (mathType) {
        case MT_ADDITION:
            mathSymbol = '+';
            correctAnswer = leftNumber + rightNumber;
            break;
        case MT_SUBTRACTION:
            mathSymbol = '-';
            //larger number on the left to avoid negative numbers
            if (leftNumber < rightNumber) {
                tempNumber = leftNumber; //storing smaller num in temp
                leftNumber = rightNumber; //put larger num in leftNumber
                rightNumber = tempNumber; //storing smaller num in rightNumber
            }
            correctAnswer = leftNumber - rightNumber;
            break;
        case MT_MULTIPLICATION:
            mathSymbol = '*';
            correctAnswer = leftNumber * rightNumber;
            break;
        case MT_DIVISION:
            mathSymbol = '/';
            //To avoid fractional answers, treat correctAnswer as the intended result
            correctAnswer = leftNumber;
            leftNumber *= rightNumber; //to make leftNumber evenly divisible
            break;
        default: //error message
            //displayed if math type is outside the valid values 1-4
            cout << "Invalid math type: " << mathType << endl;
            cout << "Please report this error to Gavin Johnson or Ben Stearns" << endl;
            cout << "Error code -1";
            exit(-1);
    }
    return {mathLevel, leftNumber, mathSymbol, rightNumber, correctAnswer};
}

/**********************************************************************************************************************
 * Determines in whatever is in the input buffer is a numeric value only. Loops until a valid number is entered
 * Returns the user's answer to a question as an int
 *********************************************************************************************************************/
int GetNumericValue() {
    int userAnswer = 0;//stores user's answer for a question

    // Validate the user's answer by looping until numeric data is entered
    while (!(cin >> userAnswer)) {
        cin.clear(); // clear the cin error flag
        // need to include the limits library to use numeric_limits
        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n'); //ignore the max input, up to '\n'
        cout << "\tInvalid input!" << endl;
        cout << "\tPlease enter a number: ";
    }
    return userAnswer;
}

/**********************************************************************************************************************
 * Defines a for loop that iterates a maximum of 3 times to answer a question correctly
 * Returns "true" if question is answered correctly. Returns "false" if incorrect.
 *********************************************************************************************************************/
bool GiveThreeAttempts(string username, vector<int> &currentQuestion) {
    //required local variables
    int userAnswer          = 0;                                            //stores user's answer to a question
    bool isCorrect          = false;                                        //whether user got the answer right or not
    int mathLevel           = currentQuestion.at(0);                     //user's current math level
    int leftNumber          = currentQuestion.at(1);                     //number to left of math symbol
    char mathSymbol         = static_cast<char>(currentQuestion.at(2));  //symbol for math question
    int rightNumber         = currentQuestion.at(3);                     //number to right of math symbol
    int correctAnswer       = currentQuestion.at(4);                     //stores question's correct answer

    cout << endl; // separate the last question from the current question

    // for loop to give the user 3 attempts to answer the question correctly
    //use the random left number, right number, and math symbol to ask the user a math question
    //give the user three attempts to answer correctly while informing them what level they are on
    for (int i = 1; i <= MAX_ATTEMPTS; i++) {
        cout << "[Level #" << mathLevel << "] " << username << ", what is "
                << leftNumber << " " << mathSymbol << " " << rightNumber << " = ";

        // Validate the user's answer by looping until numeric data is entered
        userAnswer = GetNumericValue(); // end of get userAnswer while loop

        //if user's answer is correct, increment their totalCorrect answers by 1, display "congrats" and break out
        if (userAnswer == correctAnswer) {
            cout << "\tCongratulations! You answered correctly!" << endl;
            cout << R"(
                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V)" << endl;
            cout << "\t\t\t\t*happy tail wags*" << endl << endl;
            currentQuestion.push_back(i);
            isCorrect = true;
            break; //exit loop on correct answer
        } else {
            //if the user answered incorrectly and has no attempts left, display "sorry"" and the correct answer
            //also increment the user's totalIncorrect answers by 1
            if (i >= MAX_ATTEMPTS) {
                cout << "\tSorry! You answered incorrectly..." << endl;
                cout << "\tThe correct answer was " << correctAnswer << "." << endl;
                cout << R"(
                                 /^ ^\
                                / 0 0 \
                                V\ ⁀ /V
                                 /   \
                                 |    \
                                 || (__V)" << endl;
                cout << "\t\t\t\t*sad puppy noises*" << endl << endl;
                currentQuestion.push_back(0);
                isCorrect = false;
            }
            //if the user answered incorrectly with attempts still remaining, display "sorry" and remaining attempts
            else {
                cout << "\tSorry! You answered incorrectly..." << endl;
                cout << "\t";
                cout << "\tYou have " << MAX_ATTEMPTS - i << " attempt(s) remaining" << endl;
            }
        }
    } //end of user's attempts at answering a question

    return isCorrect;
}

/**********************************************************************************************************************
 * Determines if the user is eligible for leveling up or down. Uses pass-by-reference to access/update variables
 *********************************************************************************************************************/
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel)
{
    int LEVEL_RANGE_CHANGE = 10;                        //for increasing/decreasing random numbers when leveling up/down
    int currentRange = mathLevel * LEVEL_RANGE_CHANGE;  //calculates the current range of numbers the user is on

    //check whether the user got 3 questions answered correctly
    //if so, increase their math level, range of random numbers generated, and reset totalCorrect/Incorrect to 0
    //output that they've leveled up and what their new level and range of numbers are
    if (totalCorrect == 3) {
        mathLevel++;
        totalCorrect = 0;
        totalIncorrect = 0;
        currentRange += LEVEL_RANGE_CHANGE;
        cout << "\tCongrats, you have leveled up!" << endl;
        cout << "\tYour current level is now " << mathLevel << " with numbers ranging from 1-" << currentRange <<
                endl;
    }
    //check whether user got 3 questions incorrect and their current mathLevel is greater than level 1
    //if so, decrease their math level, range of random numbers generated, and reset totalCorrect/Incorrect to 0
    //output that they've leveled down, their new math level and new range of random numbers
    if (totalIncorrect == 3 && mathLevel > 1) {
        mathLevel--;
        totalCorrect = 0;
        totalIncorrect = 0;
        currentRange -= LEVEL_RANGE_CHANGE;
        cout << "\tSorry, you answered too many questions incorrectly and leveled down" << endl;
        cout << "\tYour current level is now " << mathLevel << " with numbers ranging from 1-" << currentRange <<
                endl;
    }
}

/**********************************************************************************************************************
 * Asks the user if they want to play again. Loops until either y/yes/n/no is entered
 * Returns the user's wish to continue as a string "y/yes/n/no"
 *********************************************************************************************************************/
string YesNoQuestion(string question) {
    string userInput = "?";//stores the user's wish to continue

    //ask whether the user wishes to continue
    while (true) {
        cout << question;
        getline(cin, userInput);
        for (char & i : userInput) //cast all characters to lower case
            i = tolower(i);
        //if the user entered a valid value, break from the loop
        if (userInput == "y" || userInput == "yes" ||
            userInput == "n" || userInput == "no")
            break;
        //if the user entered an invalid value, output the result & allow loop to continue
        else {
            cout << "\tInvalid input, please try again..." << endl;
        }
    } //end validating if user wishes to continue
    return userInput;
}

/**********************************************************************************************************************
 * Parses a 2d vector containing all questions the user asked and how well they did into a final summary report
 * Returns void. Only prints the report
 *********************************************************************************************************************/
void DisplaySummaryReport(const vector<vector<int> > &allQuestions) {
    int totalCorrect    = 0;    //for storing how many questions the user got right during a playthrough
    int totalIncorrect  = 0;    //for storing how many questions the user got wrong during a playthrough

    //display summary header
    cout << "====================================" << endl;
    cout << "           Summary Report" << endl;
    cout << "====================================" << endl;
    cout << "Level    Question      Attempts" << endl;
    cout << "----- ---------------- ---------" << endl;

    // loop through the 2D vector to display all questions
    for (int i = 0; i < allQuestions.size(); i++) {
        //pull the current row's data out into more readable variables
        int mathLevel       = allQuestions.at(i).at(0);
        int leftNumber      = allQuestions.at(i).at(1);
        char mathSymbol     = static_cast<char>(allQuestions.at(i).at(2));
        int rightNumber     = allQuestions.at(i).at(3);
        int correctAnswer   = allQuestions.at(i).at(4);
        int numAttempts     = allQuestions.at(i).at(5);


        //display the question
        cout << "  " << setw(2) << right << mathLevel << "  "
                << setw(3) << right << leftNumber << " "
                << mathSymbol << setw(3) << rightNumber << " = "
                << setw(3) << correctAnswer << "  ";

        // if the user got the question correct, output the number of attempts it took
        // otherwise if the user got the question wrong, output "incorrect" instead of 0
        if (numAttempts != 0) {
            cout << "   " << numAttempts << endl;
            totalCorrect++;
        } else {
            cout << "Incorrect" << endl;
            totalIncorrect++;
        }
    }
    cout << endl;

    // calculate and output overall statistics
    cout << "Total Questions: " << setw(5) << right << allQuestions.size() << endl;
    cout << "Total Correct:   " << setw(5) << right << totalCorrect << endl;
    cout << "Total Incorrect: " << setw(5) << right << totalIncorrect << endl;
    cout << "Average Correct: " << setw(5) << right << totalCorrect * 100 / allQuestions.size() << "%" << endl;
}

/**********************************************************************************************************************
* Asks the user if they wish to save their game. If so, the results of all the user's question are written to a file
* Returns void
**********************************************************************************************************************/
void SaveCurrentGame(string username, const vector<vector<int> > &allQuestions) {
    //define required function variables
    string userInput = "?";
    ofstream outFS;

    //ask if the user wishes to save their game and store their response
    cout << endl << username;
    userInput = YesNoQuestion(", would you like to save your game? (y=yes | n=no): ");

    //if user responded "no", display game save was cancelled and return from the function
    if (userInput == "n" || userInput == "no") {
        cout << "Save game cancelled";
        return;
    }

    //display that  the game is being saved, open the file, and throw an exception if the file failed to open
    cout << "Saving game. Please wait..." << endl;
    outFS.open(FILE_NAME);
    if (!outFS.is_open()) {
        throw runtime_error("Could not open file " + FILE_NAME + " for writing");
    }

    //if file opened successfully, write the contents of the vector to the file
    for(int i = 0; i < allQuestions.size(); i++) {
        outFS << allQuestions.at(i).at(0) << " "
        << allQuestions.at(i).at(1) << " "
        << allQuestions.at(i).at(2) << " "
        << allQuestions.at(i).at(3) << " "
        << allQuestions.at(i).at(4) << " "
        << allQuestions.at(i).at(5) << " "
        << endl;
    }

    //close the file and display how many questions were saved
    outFS.close();
    cout << allQuestions.size() << " questions saved to " << FILE_NAME << endl;
    cout << "Game saved successfully." << endl;
}

/**********************************************************************************************************************
* Attempts to load the game's saved data file. If it doesn't exist, display they are a new user and return from fuction
* If file exists, load the data from within the file as a vector and return the data.
* Throw an exception if file fails to load
* Returns void
**********************************************************************************************************************/
void LoadPredictedGame(string username, vector<vector<int> > &allQuestions) {
    ifstream inFS;
    string userInput    = "?";
    int leftNumber      = 0;
    int rightNumber     = 0;
    int mathLevel       = 0;
    int mathSymbol      = 0;
    int correctAnswer   = 0;
    int attempts        = 0;

    inFS.open(FILE_NAME);

    if(!inFS.is_open()) {
        cout << "You haven't played this game before good luck on your new game"
        << endl;
        return;
    }
    userInput = YesNoQuestion("Would you like to load your previous game?");
    if(userInput == "n" || "no"){
        cout<<"You have cancelled the load"<<endl;
        return;
    }

}