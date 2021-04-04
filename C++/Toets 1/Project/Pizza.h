//
// Created by Nicolas on 27/01/2021.
//

#ifndef TOETS_PIZZA_H
#define TOETS_PIZZA_H


#include <vector>
#include <memory>
#include "Product.h"
#include "Ingredient.h"

class Pizza : public Product {
    std::vector<std::shared_ptr<Ingredient>> ingredients;

public:
    Pizza(const std::string &name, unsigned int amount);

    void addIngredients(std::shared_ptr<Ingredient>);

    const std::vector<std::shared_ptr<Ingredient>> &getIngredients() const;

    void printProduct() const;
};


#endif //TOETS_PIZZA_H
