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
 
 
double Player::heuristic(double new_val, Board* bor, Move *m)
{
                        if( new_val >= 0)
            {
			            //corners are good, and outer edge
				if(m -> getX() == 0 || m -> getX() == 7)
				{
					if(m -> getY() == 0 || m -> getY() == 7)
					{
						new_val = new_val * 100;
					}
				}
				if(m -> getX() == 0 || m -> getX() == 7) {
					if (m -> getY() == 1 || m -> getY() == 6) {
						new_val = new_val * -30;
					}	
				}
				if(m -> getX() == 1 || m -> getX() == 6) {
					if (m -> getY() == 1 || m -> getY() == 6)
					{
						new_val = new_val * -50;
					}				
				}
				if(m -> getY() == 0 || m -> getY() == 7) {
					if (m -> getX() == 1 || m -> getX() == 6) {
						new_val = new_val * -30;
					}	
				}
				if(m -> getX() == 0 || m -> getX() == 7) {
					if (m -> getY() == 2 || m -> getY() == 5) {
						new_val = new_val * 10;
					}	
				}
				if(m -> getX() == 0 || m -> getX() == 7) {
					if (m -> getY() == 3 || m -> getY() == 4) {
						new_val = new_val * 5;
					}	
				}
				if(m -> getY() == 0 || m -> getY() == 7) {
					if (m -> getX() == 3 || m -> getX() == 4) {
						new_val = new_val * 5;
					}	
				}
				if(m -> getY() == 0 || m -> getY() == 7) {
					if (m -> getX() == 2 || m -> getX() == 5) {
						new_val = new_val * 10;
					}	
				}
				if(bor -> get(Myside,0,0))
				{if(m -> getX() == 0){
					if (m -> getY() == 1)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 1){
					if (m -> getY() == 0)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 1){
					if (m -> getY() == 1)
					{
						new_val = new_val / -50;
						new_val = new_val * 20;
					}
					
					}
				}
				if(bor -> get(Myside,0,7))
				{if(m -> getX() == 0){
					if (m -> getY() == 6)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 1){
					if (m -> getY() == 7)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 1){
					if (m -> getY() == 6)
					{
						new_val = new_val / -50;
						new_val = new_val * 20;
					}
					
					}			
				}	
				if(bor -> get(Myside,7,0))
				{if(m -> getX() == 7){
					if (m -> getY() == 1)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 6){
					if (m -> getY() == 0)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 6){
					if (m -> getY() == 1)
					{
						new_val = new_val / -50;
						new_val = new_val * 20;
					}
					
					}
				}
				if(bor -> get(Myside,7,7))
				{if(m -> getX() == 6){
					if (m -> getY() == 7)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 7){
					if (m -> getY() == 6)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 6){
					if (m -> getY() == 6)
					{
						new_val = new_val / -50;
						new_val = new_val * 20;
					}
					
					}
				}
			}
				//if negative
			else
			{
			if(m -> getX() == 0 || m -> getX() == 7)
				{
					if(m -> getY() == 0 || m -> getY() == 7)
					{
						new_val = new_val * -100;
					}
				}
				if(m -> getX() == 0 || m -> getX() == 7) {
					if (m -> getY() == 1 || m -> getY() == 6) {
						new_val = new_val * 30;
					}	
				}
				if(m -> getX() == 1 || m -> getX() == 6) {
					if (m -> getY() == 1 || m -> getY() == 6)
					{
						new_val = new_val * 50;
					}				
				}
				if(m -> getX() == 0 || m -> getX() == 7) {
					if (m -> getY() == 2 || m -> getY() == 5) {
						new_val = new_val * -10;
					}	
				}
				if(m -> getX() == 0 || m -> getX() == 7) {
					if (m -> getY() == 3 || m -> getY() == 4) {
						new_val = new_val * -5;
					}	
				}
				if(m -> getY() == 0 || m -> getY() == 7) {
					if (m -> getX() == 3 || m -> getX() == 4) {
						new_val = new_val * -5;
					}	
				}
				if(m -> getY() == 0 || m -> getY() == 7) {
					if (m -> getX() == 2 || m -> getX() == 5) {
						new_val = new_val * -10;
					}	
				}
								if(bor -> get(Myside,0,0))
				{if(m -> getX() == 0){
					if (m -> getY() == 1)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 1){
					if (m -> getY() == 0)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 1){
					if (m -> getY() == 1)
					{
						new_val = new_val / -50;
						new_val = new_val * 20;
					}
					
					}
				}
				if(bor -> get(Myside,0,7))
				{if(m -> getX() == 0){
					if (m -> getY() == 6)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 1){
					if (m -> getY() == 7)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 1){
					if (m -> getY() == 6)
					{
						new_val = new_val / -50;
						new_val = new_val * 20;
					}
					
					}			
				}	
				if(bor -> get(Myside,7,0))
				{if(m -> getX() == 7){
					if (m -> getY() == 1)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 6){
					if (m -> getY() == 0)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 6){
					if (m -> getY() == 1)
					{
						new_val = new_val / -50;
						new_val = new_val * 20;
					}
					
					}
				}
				if(bor -> get(Myside,7,7))
				{if(m -> getX() == 6){
					if (m -> getY() == 7)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 7){
					if (m -> getY() == 6)
					{
						new_val = new_val / -30;
						new_val = new_val * 80;
					}
				}
					if(m -> getX() == 6){
					if (m -> getY() == 6)
					{
						new_val = new_val / -50;
						new_val = new_val * 20;
					}
					
					}
				}
			}
			
			return new_val;
} 
 
 
double Player::helper_min_max(Board* bor, Side this_side, Side oth_side, int depth, Move *last_move)
{ 
	     int ours, theirs;
	     std::vector<Move> v;
     std::vector<Move> their_moves;
	double best_worst_val = -1.1234;
	double best_val = 1.1234;
	double new_val;
	     Move *m = new Move(0,0);
	          Move mov = Move(0, 0);
	               Board* temp = new Board();
	     unsigned int i,j;
	if(depth == 0)
	{
			ours = bor -> count(this_side);
            theirs = bor -> count(oth_side);
            new_val = ours - theirs;
			new_val = heuristic(new_val, bor, last_move);

            return new_val;
            

	}
	if(bor -> isDone())
	{
					ours = bor -> count(this_side);
            theirs = bor -> count(oth_side);
            new_val = ours - theirs;
			new_val = heuristic(new_val, bor, last_move);

            return new_val;
	}

	
     for(i = 0; i < 8; i++)
     {
        for(j = 0; j < 8; j++)
        {
            m -> setX(i);
            m -> setY(j);

            if(bor -> checkMove(m, this_side))
            {

                mov = *m;
                v.push_back(mov);

            }
        }
    }

for(i = 0; i < v.size(); i++)
    {

        m = &v[i];
        temp = bor -> copy();
        temp -> doMove(m, this_side);

		new_val = helper_min_max(temp, oth_side, this_side, depth - 1, last_move);
	if(depth%2 == 1)
	{	
		if(best_worst_val == -1.1234)
		{
			best_worst_val = new_val;
		}

        if( new_val > best_worst_val)
            {
                best_worst_val = new_val;
            }
    
    }
    else{
		if(best_val == 1.1234)
		{
			best_val = new_val;
		}
        if( new_val < best_val)
        {
            best_val = new_val;
        }
    }
   }
	if(depth%2 == 1)
	{

return best_worst_val;
    
    }
    else{
return best_val;
    }
 

}

 
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 

     unsigned int i,j;
     double best_worst_val;
     double current_val = INT_MIN;
     Side opponent_side;
     std::vector<Move> v;
     std::vector<Move> their_moves;

     Move *m = new Move(0,0);
     Move *current_best = new Move(0,0);
     Move mov = Move(0, 0);
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
        best_worst_val = helper_min_max(temp, opponent_side, Myside, 4, m);

 if( best_worst_val > current_val)
{
current_best -> setX(v[i].getX());
current_best -> setY(v[i].getY());
current_val = best_worst_val;
}
}
    board -> doMove(current_best, Myside);
    return current_best;
   
}



