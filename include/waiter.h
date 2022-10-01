#include <iostream>
#include "kitchen.h"

class Waiter {
    std::string waiterName;

public:
    Waiter () {

    }
    void getOrder (int order,Kitchen &kitchen) {
        switch (order) {
            case 1:kitchen.startCooking(Kitchen::PIZZA);break;
            case 2:kitchen.startCooking(Kitchen::SALAD);break;
            case 3:kitchen.startCooking (Kitchen::SOUP);break;
            case 4:kitchen.startCooking (Kitchen::STEAK);break;
            case 5:kitchen.startCooking (Kitchen::SUSHI);break;
        }
    }
    ~Waiter() = default;
};