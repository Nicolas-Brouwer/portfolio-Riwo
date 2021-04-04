#include <iostream>
#include "Order.h"
#include "SoftDrink.h"
#include "Pizza.h"

int main() {
    std::cout << "Welcome to Cheesy Pizzas, you have ordered the following products: " << std::endl << std::endl;

    /**
     * Add method calls to your Order class below. Your program should perform the given
     * steps. Please also handle errors and print the error message when something went wrong!
     * Possible errors are:
     *  - Adding duplicate ingredients to the pizza
     *  - Errors reading the input file (In this case the file is ok, but maybe in the future we will use a wrong file)
     */

    /**
     * Nicolas Brouwer 477920
     */

    Order order;

    try {
    // TODO: Add 3x softdrink "Coca-Cola" to the order with a unit price of 2.15
    // TODO: Add 1x softdrink "Orance-Juice" to the order with a unit price of 2.65
    order.addProduct(std::make_shared<SoftDrink>("Coca-Cola", 3, 2.15));
    order.addProduct(std::make_shared<SoftDrink>("Orange-Juice", 1, 2.65));

    // TODO: Add 2x Pizza Margherita to the order, with the following ingredients:
    // Ingredient: Dough, price: 3.0
    // Ingredient: Tomato, price: 2.0
    // Ingredient: Mozzarella, price: 1.0
    // Ingredient: Oregano, price: 0.75
    order.addProduct(std::make_shared<Pizza>("Margherita", 2));
    order.getProduct("Margherita")->addIngredients(std::make_shared<Ingredient>("Dough", 3.0), order.getProduct("Margherita"));
    order.getProduct("Margherita")->addIngredients(std::make_shared<Ingredient>("Tomato", 2.0), order.getProduct("Margherita"));
    order.getProduct("Margherita")->addIngredients(std::make_shared<Ingredient>("Oregano", 0.75), order.getProduct("Margherita"));
    order.getProduct("Margherita")->addIngredients(std::make_shared<Ingredient>("Mozzarella", 1.0), order.getProduct("Margherita"));
    // TODO Add 2x Pizza Salami to the order, read the ingredients from 'input.txt'.
    // Format: [ingredient] [price]
    order.readIngredientsFromFile("input.txt", std::make_shared<Pizza>("Salami", 2));

    // TODO: Tell the Order class to print out all products and total price
    order.printOrder();

    } catch (std::runtime_error & e) {
        std::cerr << e.what() << std::endl;
    }
    // TODO: Release any memory you have allocated
    return 0;
}

