//Abraham Hussain 

// We have both added stuff and commited to the github
// - Spencer

#include "player.h"
#include <vector>
#include <climits>

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    board = new Board();
    Myside = side;
    testingMinimax = false;

    /* 
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 
     unsigned int i,j;
     int ours, theirs,  new_val;
     int current_val = INT_MIN;
     Side opponent_side;
     std::vector<Move> v;

     Move *m = new Move(0,0);
     Move mov = Move(0, 0);
     Move *current_best = new Move(0,0);
     Board* temp = new Board();
     if(Myside == WHITE)
     {
        opponent_side = BLACK;
     }
     else
     {
        opponent_side = WHITE;
     }
     board -> doMove(opponentsMove, opponent_side);
     if(!(board -> hasMoves(Myside)))
     {
        return NULL;
     }
     for(i = 0; i < 8; i++)
     {
        for(j = 0; j < 8; j++)
        {
            m -> setX(i);
            m -> setY(j);

            if(board -> checkMove(m, Myside))
            {

                mov = *m;
                v.push_back(mov);

            }
        }
    }

    for(i = 0; i < v.size(); i++)
    {

        m = &v[i];
        temp = board -> copy();
        temp -> doMove(m, Myside);
        ours = temp -> count(Myside);
        theirs = temp -> count(opponent_side);
        new_val = ours - theirs;
        if(m -> getX() == 0 || m -> getX() == 7)
        {
            if(m -> getY() == 0 || m -> getY() == 7)
            {
                new_val = new_val * 3;
            }
            else
            {
                new_val = new_val * 2;
            }
        }
        if(m -> getY() == 0 || m -> getY() == 7)
        {
            new_val = new_val * 2;
        }

        if( new_val > current_val)
        {
            current_best -> setX(m -> getX());
            current_best -> setY(m -> getY());
            current_val = new_val;
        }

    }

    board -> doMove(current_best, Myside);
    return current_best;
    
}
