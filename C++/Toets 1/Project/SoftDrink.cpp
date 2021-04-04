//
// Created by Nicolas on 27/01/2021.
//

#include <iostream>
#include "SoftDrink.h"

SoftDrink::SoftDrink(const std::string &name, unsigned int amount, double price) : Product(name, amount),
                                                                                   price(price) {}

void SoftDrink::printProduct() const {
    Product::printProduct();
    std::cout << "Soft Drink " << getName() << ", price: " << price <<std::endl;
}

double SoftDrink::getPrice() const {
    return price;
}
