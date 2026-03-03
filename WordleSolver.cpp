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
        for (int i = 0; i < 5; ++i) {
            board.push_back("_");
        }
    }
        void play() {
        resetBoard();
        display(board);
    }
};
int main() {
    WordleSolver solver;
    solver.play();

    return 0;
}
