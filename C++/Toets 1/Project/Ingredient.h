//
// Created by Nicolas on 27/01/2021.
//

#ifndef TOETS_INGREDIENT_H
#define TOETS_INGREDIENT_H


#include <string>

class Ingredient {
    std::string name;
    double price;

public:
    Ingredient(const std::string &name, double price);

    const std::string &getName() const;

    double getPrice() const;
};


#endif //TOETS_INGREDIENT_H
