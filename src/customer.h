#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

class Customer
{
private:
    std::string name;
    std::string company;
    std::string safeword;
    int id;
    int pin;

public:
    Customer(std::string name, std::string company, std::string safeword, int id, int pin) : name(name), company(company), safeword(safeword), id(id), pin(pin) {}

    std::string getName();
    std::string getCompany();
    std::string getSafeWord();
    int getId();
    int getPin();
    
    void setName(std::string newName);
    void setCompany(std::string newCompany);
    void setSafeword(std::string newSafeword);
    void setId(int newId);
    void setPin(int newPin);
};  

#endif