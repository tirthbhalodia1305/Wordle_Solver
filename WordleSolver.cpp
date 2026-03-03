#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

class WordleSolver {
private:
    std::vector<std::string> ignoreWords;
    std::vector<std::string> board;

public:
    void initializeBoard() {
        int i = 0;
        while (i < 5) {
            i = userEntry(i);
        }
        display(board);
        std::cout << std::endl;
    }

    int userEntry(int location) {
        std::string initialState = board[location];
        board[location] = "=";
        display(board);
        std::string userInput = getInput("");

        if (userInput == " " || userInput.empty()) {
            board[location] = initialState;
            return location + 1;
        } else if (userInput == "0") {
            board[location] = initialState;
            return 5;
        } else if (userInput == "1") {
            board[location] = "_";
            return std::max(location - 1, 0);
        } else {
            board[location] = userInput;
            return location + 1;
        }
    }

    std::string getInput(const std::string prompt) {
        std::cout << prompt << " ";
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    void display(const std::vector<std::string> currentBoard) {
        std::cout << "[";
        for (size_t i = 0; i < currentBoard.size(); ++i) {
            std::cout << currentBoard[i];
            if (i < currentBoard.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }

    void resetBoard() {
        board.clear();
        for (int i = 0; i < 5; i++) {
            board.push_back("_");
        }
    }

    void play() {
        std::string prompt = "Your current cell is marked with a '='.\n * Enter a letter if you know it belongs in that cell.\n * Enter a space if you want to skip to the next cell.\n * Enter '1' to move one cell back and make changes.\n * Enter '0' to exit the board editing process.";
        std::cout << prompt << std::endl;
        
        resetBoard();
        initializeBoard();
    }
};

int main() {
    WordleSolver solver;
    solver.play();
    return 0;
}
