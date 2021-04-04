//
// Created by Nicolas on 27/01/2021.
//

#ifndef TOETS_ORDER_H
#define TOETS_ORDER_H


#include <vector>
#include <memory>
#include "Product.h"

class Order {
    std::vector<std::shared_ptr<Product>> products;

public:
    void addProduct(std::shared_ptr<Product>);
    void printOrder() const;
    void readIngredientsFromFile(std::string, std::shared_ptr<Product>);
    std::shared_ptr<Product> getProduct(std::string name) const;
};


#endif //TOETS_ORDER_H
