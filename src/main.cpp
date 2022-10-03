#include <iostream>
#include "waiter.h"
#include <thread>

void getOrder (Waiter &waiterName, Kitchen &kitchenName,int meal){
    waiterName.getOrder(meal, kitchenName);
}


void startWork (Waiter &waiterName, Kitchen &kitchenName){
    for (int i = 0; i<10;i++){
        int n = std::rand()% 5 +1;
        std::this_thread::sleep_for(std::chrono::seconds(std::rand()%5 +5));
        std::cout << i+1 << " ";
        std::thread Nikolai_waiter (getOrder,std::ref(waiterName),std::ref(kitchenName),n);
        Nikolai_waiter.detach();
    }
}

void startDelivery (Kitchen &kitchenName,Deliveryman &delivery){
    while (kitchenName.checkDelivery() !=10){
        std::this_thread::sleep_for(std::chrono::seconds(30));
        kitchenName.donatePreparedMeals(delivery);

    }

}


int main() {

    Waiter Nikolai = *new Waiter ("Nikolai");
    Kitchen cafe = *new Kitchen();
    Deliveryman MihailDelivery = *new Deliveryman();

    std::thread workCafe (startWork, std::ref(Nikolai),std::ref(cafe));
    std::thread workDelivery (startDelivery,std::ref(cafe), std::ref(MihailDelivery));

    workCafe.join();
    workDelivery.join();

}
