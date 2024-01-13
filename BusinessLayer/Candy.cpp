
#include "Candy.h"
Candy::Candy(){
    color = (rand()%(numberOfCandies))+1;
    match=0;
}
Candy::Candy(int num){
    color = num;
    match=0;
}
