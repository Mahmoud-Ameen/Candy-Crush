
#ifndef CANDYCRUSH_TEMPORARYDTOS_H
#define CANDYCRUSH_TEMPORARYDTOS_H

// TODO: These Declarations are only meant for testing purposes.
//       Replace them with Business Layer DTOs When Integrating
enum Candy{
    blue,
    red,
    yellow,
    green
};
struct ObjectiveInfo{

    Candy CandyType;
    int amount;
    [[nodiscard]] bool isCompleted() const{return amount == 0;};

    ObjectiveInfo(Candy candy,int amount):CandyType(candy),amount(amount){};
};


#endif //CANDYCRUSH_TEMPORARYDTOS_H
