//
// Created by Nicolas on 27/01/2021.
//

#include <iostream>
#include "Pizza.h"

Pizza::Pizza(const std::string &name, unsigned int amount) : Product(name, amount) {}

//add ingredients to the pizza
void Pizza::addIngredients(std::shared_ptr<Ingredient> ingredient) {
    if(ingredient->getName().empty()) {
        throw std::runtime_error("ingredient cannot have empty name");
    }
    for(const auto &m : ingredients) {
        if(ingredient->getName() == m->getName()) {
            throw std::runtime_error("Duplicate ingredients are not allowed");
        }
    }
    ingredients.push_back(ingredient);
}

//print the product
void Pizza::printProduct() const {
    double totalPrice;
    for(const auto &m : ingredients) {
        totalPrice += m->getPrice();
    }

    Product::printProduct();
    std::cout << "Pizza " << getName() << ", price: " << totalPrice << std::endl;
    std::cout << "\t Ingredients: " << std::flush;
    for(const auto &m : ingredients) {
        std::cout << m->getName() << " " << m->getPrice() << " " << std::flush;
    }
    std::cout << std::endl;
}

const std::vector<std::shared_ptr<Ingredient>> &Pizza::getIngredients() const {
    return ingredients;
}




