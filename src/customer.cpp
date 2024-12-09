#include <string>
#include <iostream>
#include "customer.h"

std::string Customer::getName()
{
    return name;
}
std::string Customer::getCompany()
{
    return company;
}
std::string Customer::getSafeWord()
{
    return safeword;
}
int Customer::getId()
{
    return id;
}
int Customer::getPin()
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