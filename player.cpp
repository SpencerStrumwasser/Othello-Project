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

     unsigned int i,j, k,l;
     int ours, theirs;
     double current_val = INT_MAX;
     double new_val;
     double best_worst_val = INT_MIN;
     Side opponent_side;
     std::vector<Move> v;
     std::vector<Move> their_moves;

     Move *m = new Move(0,0);
     Move *m2 = new Move(0,0);
     Move mov = Move(0, 0);
     Move *current_best = new Move(0,0);
     Board* temp = new Board();
     Board* temp2 = new Board();
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
        for(k = 0; k < 8; k++)
            {
                for(l = 0; l < 8; l++)
                {
                    m2 -> setX(l);
                    m2 -> setY(k);

                    if(board -> checkMove(m2, Myside))
                    {

                        mov = *m2;
                        their_moves.push_back(mov);

                    }
                }
            }
        for(j = 0; j < their_moves.size(); j++)
        {
            m2 = &their_moves[j];
            temp2 = temp -> copy();
            temp2 -> doMove(m2, Myside);
            ours = temp -> count(Myside);
            theirs = temp -> count(opponent_side);
            new_val = ours - theirs;


       /*
        if (new_val > 0)
        {
            //corners are good, and outer edge
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
        // spaces leading to corner are bad
        if(m -> getX() == 0 || m -> getX() == 7) {
		    if (m -> getY() == 1 || m -> getY() == 6) {
				new_val = new_val * -2;
			}	
		}
		
		if(m -> getX() == 1 || m -> getX() == 6) {
		    if (m -> getY() == 1 || m -> getY() == 6 || 
		    m -> getY() == 0 || m -> getY() == 7) {
				new_val = new_val * -2;
			} 		
		}
        // outside circle
		if(m -> getX() == 1 || m -> getX() == 6) {
            if (m -> getY() != 1 || m -> getY() != 6 || 
            m -> getY() != 0 || m -> getY() != 7) {
                new_val = new_val * -1;
            }       
        }
        if(m -> getY() == 1 || m -> getY() == 6) {
            if (m -> getX() != 1 || m -> getX() != 6 || 
            m -> getX() != 0 || m -> getX() != 7) {
                new_val = new_val * -1;
            }       
        }
        //inside circle
        if(m -> getX() == 2 || m -> getX() == 5) {
            if (m -> getY() == 2 || m -> getY() == 3 || 
            m -> getY() == 4 || m -> getY() == 5) {
                new_val = new_val * 1.5;
            }       
        }
        if(m -> getY() == 2 || m -> getY() == 5) {
            if (m -> getX() == 2 || m -> getX() == 3 || 
            m -> getX() == 4 || m -> getX() == 5) {
                new_val = new_val * 1.5;
            }       
        }
    }
    else
    {
                if(m -> getX() == 0 || m -> getX() == 7)
        {
            if(m -> getY() == 0 || m -> getY() == 7)
            {
                new_val = new_val * - 1;
            }

        }

        
        if(m -> getX() == 0 || m -> getX() == 7) {
            if (m -> getY() == 1 || m -> getY() == 6) {
                new_val = new_val * 3;
            }   
        }
        
        if(m -> getX() == 1 || m -> getX() == 6) {
            if (m -> getY() == 1 || m -> getY() == 6 || 
            m -> getY() == 0 || m -> getY() == 7) {
                new_val = new_val * 3;
            }       
        }
        if(m -> getX() == 1 || m -> getX() == 6) {
            if (m -> getY() != 1 || m -> getY() != 6 || 
            m -> getY() != 0 || m -> getY() != 7) {
                new_val = new_val * 2;
            }       
        }
        if(m -> getY() == 1 || m -> getY() == 6) {
            if (m -> getX() != 1 || m -> getX() != 6 || 
            m -> getX() != 0 || m -> getX() != 7) {
                new_val = new_val * 2;
            }       
        }
    }
    */

            if( new_val < current_val)
            {

                current_val = new_val;
            }

        }

        if( current_val > best_worst_val)
        {
            current_best -> setX(v[i].getX());
            current_best -> setY(v[i].getY());
            best_worst_val = current_val;
        }

    }

    board -> doMove(current_best, Myside);
    return current_best;
    
}
