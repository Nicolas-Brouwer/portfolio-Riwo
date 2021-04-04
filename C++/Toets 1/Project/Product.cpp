//
// Created by Nicolas on 27/01/2021.
//

#include <iostream>
#include "Product.h"
#include "Pizza.h"
#include "SoftDrink.h"

Product::Product(const std::string &name, unsigned int amount) : name(name), amount(amount){}

unsigned int Product::getAmount() const {
    return amount;
}

const std::string &Product::getName() const {
    return name;
}

void Product::printProduct() const {
    std::cout << amount << "x " <<std::flush;
}

//add ingredients to a product. first check if the product is of type Pizza
void Product::addIngredients(std::shared_ptr<Ingredient> ingredient, std::shared_ptr<Product> product) {
    if(!std::dynamic_pointer_cast<Pizza>(product)) {
        throw std::runtime_error("product not a pizza");
    }

    std::dynamic_pointer_cast<Pizza>(product)->addIngredients(ingredient);
}

//get the total price of each product
double Product::getPrice(std::shared_ptr<Product> product) {
    if(std::dynamic_pointer_cast<SoftDrink>(product)) {
        return std::dynamic_pointer_cast<SoftDrink>(product)->getPrice() * product->getAmount();
    } else if (std::dynamic_pointer_cast<Pizza>(product)) {
        double pizzaCost;
        for (const auto &m : std::dynamic_pointer_cast<Pizza>(product)->getIngredients()) {
            pizzaCost += m->getPrice();
        }
        return pizzaCost * product->getAmount();
    } else {
        throw std::runtime_error("Something went horribly wrong");
    }
}


