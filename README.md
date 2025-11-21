<!-- 
https://github.com/lifeparticle/Markdown-Cheatsheet
https://youtu.be/eVGEea7adDM?si=cz1Fbqxr9VgioIEh
-->

# Math Tutor V6

<b>Table of Contents</b>
- [Summary](#summary)
- [Screenshots](#screenshots)
    - [Intro Screen](#intro-screen)
    - [Correct Answer](#correct-answer)
    - [Incorrect Answer](#incorrect-answer)
    - [Level Up](#level-up)
    - [Level Down](#level-down)
    - [Final Report](#final-report)
- [Maintainers](#maintainers)

# <u>*Summary*</u>

Welcome to Math Tutor Version 6!
--------------------------------
This is a fun program to test your math skills with some randomly generated math questions.
Do super well and you can level up to harder problems!
Be careful though. Get too many wrong and you might level down. Give it a try!

How does it work? Here's what this program does:
The purpose of this program is to:
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

# <u>*Screenshots*</u>

## Intro Screen
```
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ~___  ___      _   _       _____     _             ~
        ~|  \/  |     | | | |     |_   _|   | |            ~
        ~| .  . | __ _| |_| |__     | |_   _| |_ ___  _ __ ~
        ~| |\/| |/ _` | __| '_ \    | | | | | __/ _ \| '__|~
        ~| |  | | (_| | |_| | | |   | | |_| | || (_) | |   ~
        ~\_|  |_/\__,_|\__|_| |_|   \_/\__,_|\__\___/|_|   ~
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**************************************************************************************
*   Welcome to the Silly Simple Math Tutor                                           *
*   Fun Math facts:                                                                  *
*       - Without Geometry, life is pointless                                        *
*       - Why was the = sign so humble? Because it knew it wasn't > or < anyone else *
*       - Parallel lines have so much in common. It's too bad they'll never meet     *
**************************************************************************************

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
My name is Digit and I'll be your math tutor!
What is your name? Ben
Welcome Ben to the Silly Simple Math Tutor!
[Level #1] Ben, what is 6 + 1 = 

```
## Correct Answer
```
[Level #1] Ben, what is 9 - 8 = 1
        Congratulations! You answered correctly!

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
                                *happy tail wags *

Do you want to continue? (y= yes | n=no)


```

## Incorrect Answer
```
[Level #1] Ben, what is 7 * 2 = 12
        Sorry! You answered incorrectly...
        You have 2 attempt(s) remaining

```
## Level Up
```
[Level #1] Ben, what is 24 / 4 = 6
        Congratulations! You answered correctly!

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
                                *happy tail wags*

Do you want to continue? (y= yes | n=no) y
[Level #1] Ben, what is 2 + 7 = 9
        Congratulations! You answered correctly!

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
                                *happy tail wags*

Do you want to continue? (y= yes | n=no) y
[Level #1] Ben, what is 5 - 5 = 0
        Congratulations! You answered correctly!

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
                                *happy tail wags*
        Congrats, you have leveled up!
        Your current level is now 2 with numbers ranging from 1-20

Do you want to continue? (y= yes | n=no) y
[Level #2] Ben, what is 19 * 12 = 

```
## Level Down
```
[Level #2] Ben, what is 12 / 6 = 0
        Sorry! You answered incorrectly...
                You have 2 attempt(s) remaining
[Level #2] Ben, what is 12 / 6 = 0
        Sorry! You answered incorrectly...
                You have 1 attempt(s) remaining
[Level #2] Ben, what is 12 / 6 = 0
        Sorry! You answered incorrectly...
        The correct answer was 2.

                                 /^ ^\
                                / 0 0 \
                                V\ ⁀ /V
                                 /   \
                                 |    \
                                 || (__V
                                *sad puppy noises*

Do you want to continue? (y= yes | n=no) y
[Level #2] Ben, what is 15 - 10 = 0
        Sorry! You answered incorrectly...
                You have 2 attempt(s) remaining
[Level #2] Ben, what is 15 - 10 = 0
        Sorry! You answered incorrectly...
                You have 1 attempt(s) remaining
[Level #2] Ben, what is 15 - 10 = 0
        Sorry! You answered incorrectly...
        The correct answer was 5.

                                 /^ ^\
                                / 0 0 \
                                V\ ⁀ /V
                                 /   \
                                 |    \
                                 || (__V
                                *sad puppy noises*

Do you want to continue? (y= yes | n=no) y
[Level #2] Ben, what is 20 + 12 = 0
        Sorry! You answered incorrectly...
                You have 2 attempt(s) remaining
[Level #2] Ben, what is 20 + 12 = 0
        Sorry! You answered incorrectly...
                You have 1 attempt(s) remaining
[Level #2] Ben, what is 20 + 12 = 0
        Sorry! You answered incorrectly...
        The correct answer was 32.

                                 /^ ^\
                                / 0 0 \
                                V\ ⁀ /V
                                 /   \
                                 |    \
                                 || (__V
                                *sad puppy noises*
        Sorry, you answered too many questions incorrectly and leveled down
        Your current level is now 1 with numbers ranging from 1-10

Do you want to continue? (y= yes | n=no) y
[Level #1] Ben, what is 6 - 2 =


```
## Final Report
```
Do you want to continue? (y= yes | n=no) n
====================================
           Summary Report
====================================
Level    Question      Attempts
----- ---------------- ---------
   1    8 -  7 =   1     1
   1    4 *  4 =  16     3
   1   80 / 10 =   8  Incorrect
   1    6 +  8 =  14     2

Total Questions:     4
Total Correct:       3
Total Incorrect:     3
Average Correct:    75%

```

# <u>*Maintainers*</u>
[@JayW259](https://github.com/JayW259) Javion Wilkins <br>
[@bstearns07](https://github.com/bstearns07) Ben Stearns

[Back to Top](#math-tutor-v6)
