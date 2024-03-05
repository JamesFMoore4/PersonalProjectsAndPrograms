#include <iostream>
#include <vector>
#include <ctime>

void generate(std::vector<std::vector<int>> &snakes, std::vector<std::vector<int>> &ladders);
bool filter(std::vector<std::vector<int>> vect, int random, int random2);
void update(int &p1, int &p2, std::vector<std::vector<int>> snakes, std::vector<std::vector<int>> ladders);
void check(int &p, std::vector<std::vector<int>> snakes, std::vector<std::vector<int>> ladders);


void generate(std::vector<std::vector<int>> &snakes, std::vector<std::vector<int>> &ladders) {

    srand(time(NULL));

    //Generate vector of snakes
    int i = 0;
    while (i < 5) {
        int random = rand() % 99 + 2;
        int random2 = rand() % 99 + 2;
        if (i != 0) {
            filter(snakes, random, random2);
        }
        if (random <= random2 || (i > 0 && filter(snakes, random, random2))) {
            continue;
        }
        else {
            std::vector<int> snake = {random, random2};
            snakes.push_back(snake);
        }

        i++;
    }

    //Generate vector of ladders
    int j = 0;
    while (j < 5) {
        int random = rand() % 99 + 2;
        int random2 = rand() % 99 + 2;
        if (random >= random2 || (i >= 0 && filter(snakes, random, random2)) || (i > 0 && filter(ladders, random, random2))) {
            continue;
        }
        else {
            std::vector<int> ladder = {random, random2};
            ladders.push_back(ladder);
        }

        j++;
    }

}

bool filter(std::vector<std::vector<int>> vect, int random, int random2) {

    //Filters out non-unique values
    for (int x = 0; x < vect.size(); x++) {
        for (int y = 0; y < 2; y++) {
            if (vect[x][y] == random || vect[x][y] == random2) {
                return true;
            }
        }
    }

    return false;
}

void update(int &p1, int &p2, std::vector<std::vector<int>> snakes, std::vector<std::vector<int>> ladders) {

    std::cout << "Player 1 Position: " << p1 << "\n";
    std::cout << "Player 2 Position: " << p2 << "\n";
    
    srand(time(NULL));

    int random1 = rand() % 6 + 1;
    int random2 = rand() % 6 + 1;

    p1 += random1;
    p2 += random2;

    std::cout << "Player 1 rolled a " << random1 << ". Player 1 moves to position " << p1 << ".\n";

    if (p1 >= 100) {
        std::cout << "Player 1 wins!";
    }
    else {
        int temp = p1;
        check(p1, snakes, ladders);
        if (p1 != temp) {
            std::cout << "Player 1 moves to position " << p1 << ".\n";
        }
    }

    if (!(p1 >= 100)) {

        std::cout << "Player 2 rolled a " << random2 << ". Player 1 moves to position " << p2 << ".\n";

        if (p2 >= 100) {
        std::cout << "Player 2 wins!";
        }
        else {
            int temp = p2;
            check(p2, snakes, ladders);
            if (p2 != temp) {
                std::cout << "Player 2 moves to position " << p2 << ".\n";
            }
        }

    }
}

void check(int &p, std::vector<std::vector<int>> snakes, std::vector<std::vector<int>> ladders) {

    for (int i = 0; i < snakes.size(); i++) {
        if (snakes[i][0] == p) {
            std::cout << "Snake! ";
            p = snakes[i][1];
            break;
        }
    }

    for (int i = 0; i < ladders.size(); i++) {
        if (ladders[i][0] == p) {
            std::cout << "Ladder! ";
            p = ladders[i][1];
            break;
        }
    }

}

int main() {

    std::vector<std::vector<int>> snakes;
    std::vector<std::vector<int>> ladders;
    int p1 = 0;
    int p2 = 0;

    generate(snakes, ladders);

    while (p1 < 100 && p2 < 100) {
        update(p1, p2, snakes, ladders);
    }

    return 0;
}