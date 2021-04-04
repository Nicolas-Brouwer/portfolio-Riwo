//
// Created by Nicolas on 27/01/2021.
//

#include <iostream>
#include <fstream>
#include "Order.h"

void Order::addProduct(std::shared_ptr<Product> product) {

    if(product->getName().empty() || product->getAmount() == 0) {
        throw std::runtime_error("error: name of product cant be empty or product amount cant be 0");
    }


    products.push_back(product);
}

void Order::printOrder() const {
    double finalPrice;

    for (const auto &p : products) {
        p->printProduct();
        finalPrice += p->getPrice(p);
    }
    std::cout << "" << std::endl;
    std::cout << "your total price is: " << finalPrice << std::endl;


}

std::shared_ptr<Product> Order::getProduct(std::string name) const {
    for(const auto &p : products) {
        if(p->getName() == name) {
            return p;
        }
    }
    throw std::runtime_error("could not find product (incorrect name)");
}

void Order::readIngredientsFromFile(std::string file, std::shared_ptr<Product> product) {
    std::ifstream input(file);
    addProduct(product);

    while(true) {
        std::string ingredient;
        double price;

        input >> ingredient >> price;

        if(input.eof()) {
            return;
        }
        if(input.fail()) {
            throw std::runtime_error("something went wrong");
        }
        product->addIngredients(std::make_shared<Ingredient>(ingredient, price), product);
    }
}



