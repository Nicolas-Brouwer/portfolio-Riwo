//
// Created by Nicolas on 27/01/2021.
//

#ifndef TOETS_PRODUCT_H
#define TOETS_PRODUCT_H


#include <string>
#include <memory>
#include "Ingredient.h"

class Product {
    std::string name;
    unsigned int amount;

public:
    Product(const std::string &name, unsigned int amount);

    virtual ~Product(){};

    unsigned int getAmount() const;

    const std::string &getName() const;

    virtual void printProduct() const;

    void addIngredients(std::shared_ptr<Ingredient>, std::shared_ptr<Product>);

    double getPrice(std::shared_ptr<Product>);
};


#endif //TOETS_PRODUCT_H
