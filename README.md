# Math Tutor V6
<p align="center"> <img src="https://img.shields.io/badge/C++-Program-blue?style=flat-square&logo=cplusplus" /> <img src="https://img.shields.io/badge/Leveling-Dynamic-success?style=flat-square" /> <img src="https://img.shields.io/badge/Status-Complete-brightgreen?style=flat-square" /> <img src="https://img.shields.io/badge/Focus-Problem%20Solving-orange?style=flat-square" /> </p>

---

## 👤 Author
Ben Stearns - [@bstearns07](https://github.com/bstearns07)

📅 Last Updated: 12-13-26

---

## 📑 Table of Contents
- 📌 [Summary](#-summary)
- ⭐ [How It Works](#-how-it-works)
- ✨ [Features](#-features)
- 🧰 [Tech Stack](#-tech-stack)
- 🔧 [Development Tools](#-development-tools)
- 🧩 [Core Concepts](#-core-concepts)
- 📝 [New Topics Covered](#-new-topics-covered)
- 📘 [What I Learned](#-what-i-learned)
- 🖼 [Screenshots](#-screenshots)

---

## 📌 Summary

**Math Tutor V6** is an interactive console-based C++ application designed to help users practice math skills in a fun and engaging way.

The program dynamically generates math problems, tracks user performance, adjusts difficulty levels, and provides a detailed summary report at the end of each session.

It also introduces persistent game state by allowing users to **save and load progress**, making it more realistic and user-friendly.

---

## ⭐ How It Works

1. 🎉 Displays a fun intro with ASCII art and humor  
2. 👤 Prompts the user for their name  
3. 💾 Checks for existing saved progress  
   - Option to **load previous game** or start fresh  
4. 🔢 Generates random math problems based on difficulty level  
5. 🎯 Gives the user **3 attempts** per question  
6. 📈 Tracks performance:
   - Levels **increase after 3 correct answers**
   - Levels **decrease after 3 incorrect answers**
7. 🔁 Prompts the user to continue after each question  
8. 📊 Displays a **final performance report**  
9. 💾 Saves progress before exiting  

---

## ✨ Features

- 🎲 Random math problem generation  
- 🎯 Three-attempt answer system  
- 📊 Performance tracking (correct / incorrect / percentage)  
- 📈 Dynamic difficulty scaling (level up / down)  
- 💾 Save & load game progress  
- ⚠️ Input validation for numeric answers and user choices  
- 🧠 Uses vectors to store question history  
- 🐶 Fun ASCII art and personality  

---

## 🧰 Tech Stack

- ⚙️ **Language:** C++  
- 📦 **Libraries Used:**
  - `<iostream>` – input/output  
  - `<vector>` – dynamic data storage  
  - `<cstdlib>` / `<ctime>` – random number generation  
  - `<iomanip>` – formatted output  
  - `<stdexcept>` – exception handling  
  - `<windows.h>` – UTF-8 console support  

---

## 🔧 Development Tools

- 💻 Visual Studio / VS Code  
- 🧪 Windows Console  
- 🔍 Debugging tools  
- 🗂 Modular design with:
  - Header files (`.h`)  
  - Implementation files (`.cpp`)  

---

## 🧩 Core Concepts

- 🎲 Random number generation with seeding  
- 🔁 Looping structures (`do/while`)  
- 📦 Vectors (including **2D vectors**)  
- 🧠 Conditional logic and state tracking  
- ⚠️ Exception handling (`try/catch`)  
- 🧾 File I/O for saving and loading data  
- 🧩 Modular programming (separation of concerns)  

---

## 📝 New Topics Covered

- 💾 Persistent storage (Save/Load system)  
- ⚠️ Runtime error handling using exceptions  
- 🧱 Multi-file program structure  
- 📊 Advanced data tracking using nested vectors  
- 🎮 Game-like progression system (leveling logic)  

---

## 📘 What I Learned

This was the culmination of my first college class in C++. I've had plenty of programming experience before this, so I got to take all those skill and apply them to C++. Everything from the basics of variables/math/conditional statements to aspects unique to C++ such as function prototypes, header files, and report generation I learned a lot from this program and had a lot of fun.

Specifics topics learned:

- Designing **interactive console applications**
- Implementing **data persistence in C++**
- Structuring programs using **modular architecture**
- Handling **user input safely and effectively**
- Building **state-driven logic systems**
- Creating a more polished **user experience in terminal apps**

---

## 🖼 Screenshots

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
Ben, looks like you haven't played this game before good luck on your new game

[Level #1] Ben, what is 10 * 3 = 

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

## Loading/Saving Game Progress
```
What is your name? Ben
Welcome Ben to the Silly Simple Math Tutor!

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
My name is Digit the dog, and I'll be your math tutor!
Would you like to load the previous game that was played (y=yes | n=no)?: y
  Attempting to load game please wait
  1 have been loaded from the file

[Level #1] Ben, what is 2 * 7 =

Ben, would you like to save your game? (y=yes | n=no): y
  Saving game. Please wait...
  4 questions saved to mathtutor.txt
  Game saved successfully.

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
[Digit:] Thanks for playing the silly simple math tutor Ben!

Process finished with exit code 0

```
## Loading Game Error Handling
```
Would you like to load the previous game that was played (y=yes | n=no)?: y
Attempting to load game please wait
  Could not read the entire file mathtutor.txt for loading

[Level #1] Ben, what is 6 / 3 =

```

# <u>*Maintainers*</u>
[@JayW259](https://github.com/JayW259) Javion Wilkins <br>
[@bstearns07](https://github.com/bstearns07) Ben Stearns

[Back to Top](#math-tutor-v6)
