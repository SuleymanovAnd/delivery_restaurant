#include <iostream>
#include <utility>
#include "kitchen.h"
#pragma once
class Waiter {
    std::string waiterName;

public:
    Waiter (std::string name) : waiterName(std::move(name))
    {    }

    void getOrder (int order,Kitchen &kitchen) {
        switch (order) {
            case 1:std::cout << waiterName << " get Order: " << " pizza. " << std::endl;kitchen.startCooking(Kitchen::PIZZA);break;
            case 2:std::cout << waiterName << " getOrder: " << " salad. " << std::endl;kitchen.startCooking(Kitchen::SALAD);break;
            case 3:std::cout << waiterName << " getOrder: " << " soup. " << std::endl;kitchen.startCooking (Kitchen::SOUP);break;
            case 4:std::cout << waiterName << " getOrder: " << "steak. "<< std::endl;kitchen.startCooking (Kitchen::STEAK);break;
            case 5:std::cout << waiterName << " getOrder: " << " sushi. "<< std::endl;kitchen.startCooking (Kitchen::SUSHI);break;
        }
    }
    ~Waiter() = default;
};