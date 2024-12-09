#include <string>
#include <iostream>
#include "customer.h"
#include "database.h"

std::string Customer::getName() const
{
    return name;
}
std::string Customer::getCompany() const
{
    return company;
}
std::string Customer::getSafeWord() const
{
    return safeword;
}
int Customer::getId() const
{
    return id;
}
int Customer::getPin() const
{
    return pin;
}

void Customer::setName(std::string newName)
{
    name = newName;
}
void Customer::setCompany(std::string newCompany)
{
    company = newCompany;
}
void Customer::setSafeword(std::string newSafeword)
{
    safeword = newSafeword;
}
void Customer::setId(int newId)
{
    id = newId;
}
void Customer::setPin(int newPin)
{
    pin = newPin;
}

void Customer::createNewCustomer()
{
    int id;
    int pin;
    std::string name;
    std::string company;
    std::string safeWord;

    std::cout << "Enter Customer ID: ";
    std::cin >> id;
    std::cout << "Enter Customer name: ";
    std::cin >> name;
    std::cout << "Enter Customer Company: ";
    std::cin >> company;
    std::cout << "Enter Customer PIN: ";
    std::cin >> pin;
    std::cout << "Enter Customer safeword: ";
    std::cin >> safeWord;

    Customer newCustomer(id, name, company, safeWord, pin);
}