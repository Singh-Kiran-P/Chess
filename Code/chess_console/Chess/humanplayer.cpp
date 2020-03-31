#include "humanplayer.h"

Position HumanPlayer::moveFrom(Color playerColor) {
        std::string curr{};

        do {
            curr = "";
            std::cout << "Move which pawn? ";
            std::cin >> curr;
            curr[0] = toupper(curr[0]);
        } while (checkInput(curr) == false);

        Position currPos{curr};
        return currPos;
};

Position HumanPlayer::moveTo(Position currPos, Color playerColor) {
    std::string next{};

    do {
        next = "";
        std::cout << "To where? ";
        std::cin >> next;
        next[0] = toupper(next[0]);
    } while (checkInput(next) == false);

    Position nextPos{next};
    return nextPos;
}

HumanPlayer::HumanPlayer(string nameStr, Color color) : Player(nameStr, color) {};
