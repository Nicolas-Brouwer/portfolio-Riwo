//
// Created by Nicolas on 27/01/2021.
//

#ifndef TOETS_SOFTDRINK_H
#define TOETS_SOFTDRINK_H


#include "Product.h"

class SoftDrink : public Product {
    double price;
public:
    SoftDrink(const std::string &name, unsigned int amount, double price);

    void printProduct() const;

    double getPrice() const;
};


#endif //TOETS_SOFTDRINK_H
