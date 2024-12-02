#include <iostream>
#include "dbmgmt.h"



int main () {
    user myUser("1", "2", "3", 4, 5);
    myUser.createUser();
    myUser.display();
}