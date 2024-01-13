//
// Created by Laila on 12/25/2023.
//

#ifndef PROJECTTESTING_CANDY_H
#define PROJECTTESTING_CANDY_H

#include <iostream>
#include <time.h>

using namespace std;
/* Short description...

 Class candy each candy has its color or its number
 candies are numbered from 1 to 5
 each candy has a match data attribute which indicates this candy should be poped or not
 match is 0 this means that the candy remains, otherwise candy is poped by updateboard() method in the boardmanager
 Checkboard() in the board manager is the one responsible for setting the match attribute for all the candies in the grid
 most of the time the match will be 0 or 1 but it might be 2 or 3 if the player poped 4 candies or more (not only 3)
 so if the match is greater than 1 this reflects higher score

 */
class Candy{
public:

    int color;
    int match;
    int numberOfCandies = 7;
    Candy();
    Candy(int num);
    bool operator ==(const Candy &C){
        if (color==C.color) return true;
        return false;
    }
    friend ostream&  operator << (ostream& out,  Candy & c){
        cout<<c.color;
        return out;
    }
};


#endif //PROJECTTESTING_CANDY_Hgffffffff
