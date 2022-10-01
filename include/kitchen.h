#include <iostream>
#include <thread>
#include <mutex>
#include "deliveryman.h"


class Kitchen {
std::mutex *cooking;
public:
        enum dish {
            PIZZA,
            SOUP,
            SALAD,
            SUSHI,
            STEAK,
        };

private: dish order;
public:
    void startCooking (dish inOrder, Deliveryman &delivery){
        cooking->lock();
        order = inOrder;
        std::cout << "Kitchen start cooking :" << order;
       std::this_thread::sleep_for(std::chrono::seconds(std::rand()% 15 +5));

    }

};