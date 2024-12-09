#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>
#include <sqlite3.h>
#include "customer.h"

class Database
{
private:
    sqlite3* db;

public:
    Database() {}

    bool createTable();
    bool insertCustomer(Customer &customer);
    void printAllCustomers();

};

#endif