#include <iostream>
#include "customer.h"
#include "database.h"

int main() {
    Database db("C:\\chas\\SUVx24\\C++\\Boilerroom7.1\\Database.db");

    // Create table
    if (db.createTable()) 
    {
        std::cout << "Table created successfully or already exists." << std::endl;
    } else 
    {
        std::cerr << "Failed to create table." << std::endl;
    }

    // Create a customer object
    Customer customer1(1, "John Doe", "TechCorp", "superSecret", 1234);
    // adding customer doesnt work, need to merge everything with a menu and then implement the logic to that menu.
    if (db.addCustomer(customer1)) {
        std::cout << "Customer added successfully!" << std::endl;
    } else {
        std::cerr << "Failed to add customer." << std::endl;
    }

    // Get and print all customers
    db.getAllCustomers();

    return 0;
}