#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

class Customer
{
private:
    int id;
    std::string name;
    std::string company;
    std::string safeword;
    int pin;

public:
    Customer(int id, std::string name, std::string company, std::string safeword, int pin) : name(name), company(company), safeword(safeword), id(id), pin(pin) {}

    int getId() const;
    std::string getName() const;
    std::string getCompany() const;
    std::string getSafeWord() const;
    int getPin() const;
    
    void setName(std::string newName);
    void setCompany(std::string newCompany);
    void setSafeword(std::string newSafeword);
    void setId(int newId);
    void setPin(int newPin);

    void createNewCustomer();
};  

#endif