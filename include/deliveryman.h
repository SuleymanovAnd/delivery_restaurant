#include <iostream>

#include <thread>
#pragma once
class Deliveryman {

public:
    Deliveryman (){

    }
    void receiveADeliveryOrder(std::string order){
        std::cout << "Dish "<< order <<" sent for delivery"<<std::endl;
    }
    ~Deliveryman()=default;
};