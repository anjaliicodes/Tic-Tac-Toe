#include <SFML/Graphics.hpp>
#include <vector>

// Global constants
const int WINDOW_SIZE = 600;
const int CELL_SIZE = WINDOW_SIZE / 3;

// Game state variables
int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
int currentPlayer = 1; // 1 = X (Red), 2 = O (Blue)
int winner = 0;        // 0 = none, 1 = X, 2 = O, 3 = Draw

// Function to check if there's a winner or a draw
void checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) winner = board[i][0];
        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) winner = board[0][i];
    }
    
    // Check diagonals
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) winner = board[0][0];
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) winner = board[0][2];

    // Check for a draw if no winner yet
    if (winner == 0) {
        bool emptySpaceFound = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) emptySpaceFound = true;
            }
        }
        if (!emptySpaceFound) winner = 3; // 3 indicates a draw
    }
}

// Function to reset the game
void resetGame() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
    currentPlayer = 1;
    winner = 0;
}

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Tic Tac Toe");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window event
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Mouse click event
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // If game is over, a click anywhere resets it
                if (winner != 0) {
                    resetGame();
                } else {
                    // Calculate which cell was clicked based on mouse coordinates
                    int x = event.mouseButton.x / CELL_SIZE;
                    int y = event.mouseButton.y / CELL_SIZE;

                    // Ensure the click is within bounds and the cell is empty
                    if (x >= 0 && x < 3 && y >= 0 && y < 3 && board[y][x] == 0) {
                        board[y][x] = currentPlayer;
                        checkWin();
                        
                        // Switch player
                        currentPlayer = (currentPlayer == 1) ? 2 : 1;
                    }
                }
            }
        }

        // Clear the screen with a white background
        window.clear(sf::Color::White);

        // 1. Draw the Grid Lines
        sf::RectangleShape lineVertical(sf::Vector2f(5, WINDOW_SIZE));
        lineVertical.setFillColor(sf::Color::Black);
        for (int i = 1; i < 3; i++) {
            lineVertical.setPosition(i * CELL_SIZE - 2.5f, 0);
            window.draw(lineVertical);
        }

        sf::RectangleShape lineHorizontal(sf::Vector2f(WINDOW_SIZE, 5));
        lineHorizontal.setFillColor(sf::Color::Black);
        for (int i = 1; i < 3; i++) {
            lineHorizontal.setPosition(0, i * CELL_SIZE - 2.5f);
            window.draw(lineHorizontal);
        }

        // 2. Draw the X's and O's
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                int centerX = col * CELL_SIZE + CELL_SIZE / 2;
                int centerY = row * CELL_SIZE + CELL_SIZE / 2;

                if (board[row][col] == 1) { 
                    // Draw 'X' using two rotated rectangles
                    sf::RectangleShape line1(sf::Vector2f(160, 10));
                    line1.setFillColor(sf::Color::Red);
                    line1.setOrigin(80, 5); // Center the origin
                    line1.setPosition(centerX, centerY);
                    line1.setRotation(45);
                    window.draw(line1);

                    sf::RectangleShape line2(sf::Vector2f(160, 10));
                    line2.setFillColor(sf::Color::Red);
                    line2.setOrigin(80, 5);
                    line2.setPosition(centerX, centerY);
                    line2.setRotation(-45);
                    window.draw(line2);

                } else if (board[row][col] == 2) { 
                    // Draw 'O' using a hollow circle
                    sf::CircleShape circle(60);
                    circle.setFillColor(sf::Color::Transparent);
                    circle.setOutlineThickness(10);
                    circle.setOutlineColor(sf::Color::Blue);
                    circle.setOrigin(60, 60); // Center the origin
                    circle.setPosition(centerX, centerY);
                    window.draw(circle);
                }
            }
        }

        // Display everything we just drew
        window.display();
    }

    return 0;
}