#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.h"
#include "board.h"
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();
    double heuristic(double new_val, Board* bor, Move *m);
    double helper_min_max(Board* bor, Side this_side, Side oth_side, int depth, Move *last_move);
    Move *doMove(Move *opponentsMove, int msLeft);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
    Board* board;
    Side Myside;

};

#endif
