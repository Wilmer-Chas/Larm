#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <optional>
#include <iostream>
#include <sqlite3.h>
#include "customer.h"

class Database {
private:
    sqlite3* db;

    // Helper function for SQL execution
    bool executeSQL(const std::string& sql);

public:
    // Constructor/Destructor
    Database(const std::string& dbName);
    ~Database();

    // Core methods
    bool createTable();
    bool addCustomer(const Customer& customer);
    std::optional<Customer> getCustomerById(int id);
    bool updateCustomer(const Customer& customer);
    bool deleteCustomer(int id);
    std::vector<Customer> getAllCustomers();
};

#endif
