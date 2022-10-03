#include <iostream>
#include <thread>
#include <mutex>
#include "deliveryman.h"
#include <vector>

#pragma onece

class Kitchen {
    std::mutex *cooking;
   std::vector <std::string> dishesFinishName;
   int DeliveredOrder;
;
public:
        enum dish {
            PIZZA,
            SOUP,
            SALAD,
            SUSHI,
            STEAK,
        };

private:
    dish order;
    std::string orderString [5] = {"pizza","soup","salad", "sushi","steak"};
public:

    Kitchen (){
        cooking = new std::mutex ();

    }
    void startCooking (dish inOrder){
        cooking->lock();
        order = inOrder;
        std::cout << "Kitchen start cooking :" << orderString[order]<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(std::rand()% 15 +5));
        std::cout << "Kitchen finish cooking :" << orderString[order]<<std::endl;
        cooking->unlock();
        dishesFinishName.push_back(orderString[order]);

    }

    void donatePreparedMeals (Deliveryman &delivery){
        while (!dishesFinishName.empty()){
            std::cout << DeliveredOrder+1 << " ";
            delivery.receiveADeliveryOrder(dishesFinishName.back());
            ++ DeliveredOrder;
            dishesFinishName.pop_back();
        }

    }

    int checkDelivery (){
        return DeliveredOrder;
    }

};


