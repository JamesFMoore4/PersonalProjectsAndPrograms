#include <iostream>
#include <ctime> 

void drawBoard(char moves[]) {

    std::cout << "     " << "|" << "     " << "|" << "     " << "\n";
    std::cout << "  " << moves[0] << "  " << "|" << "  " << moves[1] << "  " << "|" << "  " << moves[2] << "  " << "\n";
    std::cout << "_____" << "|" << "_____" << "|" << "_____" << "\n";
    std::cout << "     " << "|" << "     " << "|" << "     " << "\n";
    std::cout << "  " << moves[3] << "  " << "|" << "  " << moves[4] << "  " << "|" << "  " << moves[5] << "  " << "\n";
    std::cout << "_____" << "|" << "_____" << "|" << "_____" << "\n";
    std::cout << "     " << "|" << "     " << "|" << "     " << "\n";
    std::cout << "  " << moves[6] << "  " << "|" << "  " << moves[7] << "  " << "|" << "  " << moves[8] << "  " << "\n";
    std::cout << "     " << "|" << "     " << "|" << "     " << "\n\n";
   
}

void drawPositions() {

    std::cout << "     " << "|" << "     " << "|" << "     " << "\n";
    std::cout << "  " << 1 << "  " << "|" << "  " << 2 << "  " << "|" << "  " << 3 << "  " << "\n";
    std::cout << "_____" << "|" << "_____" << "|" << "_____" << "\n";
    std::cout << "     " << "|" << "     " << "|" << "     " << "\n";
    std::cout << "  " << 4 << "  " << "|" << "  " << 5 << "  " << "|" << "  " << 6 << "  " << "\n";
    std::cout << "_____" << "|" << "_____" << "|" << "_____" << "\n";
    std::cout << "     " << "|" << "     " << "|" << "     " << "\n";
    std::cout << "  " << 7 << "  " << "|" << "  " << 8 << "  " << "|" << "  " << 9 << "  " << "\n";
    std::cout << "     " << "|" << "     " << "|" << "     " << "\n\n";
   
}

void getInput(char moves[]) {

    int point = -1;

    std::cout << "Enter a position (1-9): ";
    while(!(std::cin >> point) && moves[point] != ' ' && point < 1 && point > 9) {
        std::cout << "Position taken or invalid. Please enter a position 1-9: ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    moves[point - 1] = 'X';

}

void cmpMove(char moves[]) {
    
    srand(time(NULL));

    int point = rand() % 9 + 1;
    while (moves[point] != ' ') {
        point = rand() % 9 + 1;
    }

    moves[point] = 'O';
    
}

bool winCheck(char moves[]) {
    if (moves[0] == moves[1] && moves[1] == moves[2] && moves[0] != ' ') {
        return true;
    }
    else if (moves[3] == moves[4] && moves[4] == moves[5] && moves[3] != ' ') {
        return true;
    }   
    else if (moves[6] == moves[7] && moves[7] == moves[8] && moves[6] != ' ') {
        return true;
    }
    else if (moves[0] == moves[3] && moves[3] == moves[6] && moves[0] != ' ') {
        return true;
    }
    else if (moves[1] == moves[4] && moves[4] == moves[7] && moves[1] != ' ') {
        return true;
    }
    else if (moves[2] == moves[5] && moves[5] == moves[8] && moves[2] != ' ') {
        return true;
    }
    else if (moves[0] == moves[4] && moves[4] == moves[8] && moves[4] != ' ') {
        return true;
    }
    else if (moves[2] == moves[4] && moves[4] == moves[6] && moves[4] != ' ') {
        return true;
    }

    return false;
}
 
int main() {

    std::cout << "********** TIC-TAC-TOE **********" << "\n\n";

    while (true) {
        char moves[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        std::cout << "Positions: " << "\n";
        drawPositions();
        std::cout << "Game Board: " << "\n";
        drawBoard(moves);

        while (true) {
            std::cout << "Your turn: " << "\n";
            getInput(moves);
            drawBoard(moves);
            if (winCheck(moves)) {
                std::cout << "You Win!" << "\n";
                break;
            }
            std::cout << "Computer turn: " << "\n";
            cmpMove(moves);
            drawBoard(moves);
            if(winCheck(moves)) {
                std::cout << "You Lose!" << "\n";
                break;
            }
        }

        std::cout << "Would you like to play again? (y/n): ";
        char answer = 'z';
        while (!(std::cin >> answer) && (answer != 'y' || answer != 'n' || answer != 'Y' || answer != 'N')) {
            std::cout << "Would you like to play again? (y/n)";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }
        if (answer == 'n' || answer == 'N') {
            break;
        }

    }

    return 0;
}