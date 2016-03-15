This is the README


Group member contribution: 
Everytime our group worked, we discussed the strategy we would implement and we used 
one computer to write the code. We did this, because we found Github to cause merge 
conflicts when we both coded at the same time. Instead we took turns writing the code 
whenever one of us had an idea to make a change. Spencer worked mostly on the minimax
portion while I [Abraham] worked on the heuristics. 

Improvements: 
The improvements we made were that we updated our heuristics so it would change with 
time (when a corner was taken the spots surrounding the corner were now good spaces). We 
also fixed our minimax, so it was called recursively instead of hard coded. We found that 
a hard coded minimax gets too confusing if we try to search deeper. We also had to change 
what we weighed each position on the board so that the corners were picked most often, 
the positions adjacent to the corners were picked least often, edges were favored, and the
inner circle one square in was not favored. 