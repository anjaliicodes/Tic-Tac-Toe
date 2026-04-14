C++ SFML Tic-Tac-Toe
====================

A classic, 2D graphical Tic-Tac-Toe game built using C++ and the Simple and Fast Multimedia Library (SFML). 

This project demonstrates how to handle window creation, basic rendering (shapes and colors), event polling (mouse clicks), and 2D grid logic in C++.

FEATURES
--------
* Interactive GUI: Play the classic game on a clean, responsive 3x3 grid.
* Visual Indicators: Custom-drawn Red X's and Blue O's.
* Win/Draw Detection: The game automatically detects when a player wins or if the board fills up.
* Instant Reset: Click anywhere on the screen after a game ends to instantly clear the board and play again.

PREREQUISITES
-------------
To compile and run this project, you need:
* A C++ compiler (e.g., GCC, Clang, or MSVC)
* SFML (Simple and Fast Multimedia Library) version 2.x installed on your system.

INSTALLATION & COMPILATION
--------------------------

[ Linux (Debian/Ubuntu) ]
1. Install the SFML development libraries:
   sudo apt-get install libsfml-dev

2. Compile the game:
   g++ main.cpp -o tictactoe -lsfml-graphics -lsfml-window -lsfml-system

3. Run the executable:
   ./tictactoe


[ macOS ]
1. Install SFML using Homebrew:
   brew install sfml

2. Compile the game:
   g++ main.cpp -o tictactoe -lsfml-graphics -lsfml-window -lsfml-system

3. Run the executable:
   ./tictactoe


[ Windows (Visual Studio) ]
1. Download the pre-compiled SFML binaries for your version of Visual Studio from the official SFML website.
2. Extract the files and configure your Visual Studio project to link against the SFML include and library directories. 
3. Ensure you link the following dependencies in your project settings:
   - sfml-graphics.lib
   - sfml-window.lib
   - sfml-system.lib
4. Build and run via the IDE. (Note: make sure the SFML .dll files are in the same directory as your compiled .exe).

HOW TO PLAY
-----------
1. Launch the game.
2. Player 1 (Red 'X') always goes first.
3. Left-click an empty square to place your mark.
4. Player 2 (Blue 'O') goes next.
5. Get 3 in a row (horizontally, vertically, or diagonally) to win.
6. Once the game ends, left-click anywhere on the window to start a new round.

LICENSE
-------
This project is open-source and available under the MIT License.
