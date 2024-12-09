#include <iostream>
#include <sqlite3.h>
#include <string>
#include <sstream>

class User 
{
public: 
    std::string name;
    std::string company;
    std::string safeword;
    int id;
    int pin;
    User(std::string name, std::string company, std::string safeword, int id, int pin) : name(name), company(company), safeword(safeword), id(id), pin(pin) {}

    void display() const
    {
        std::cout << "ID: " << id << "\nName: " << name << "\nCompany: " << company << "\nSafeword: " << safeword << "\nPin: " << pin << "\n" << std::endl;
    }
};

// dragon dragon ball macorini glato :O
class DDBMGMT
{
private:

public:
    static int callback(void *data, int argc, char **argv, char **azColName)
    {
        // Iterate through the columns in the result set
        for(int i = 0; i < argc; i++)
        {
            std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
        }
        std::cout << std::endl; // Optional, can be removed if not needed

        // Ensure that we have enough arguments to create a User object
        if (argc >= 5) 
        {
            // Creating a User object from the query result
            User user(
                argv[1],              // name
                argv[2],              // company
                argv[4],              // safeword
                std::stoi(argv[0]),   // id
                std::stoi(argv[3])    // pin
            );
            user.display();  // Display user information
        }

        return 0;
    }
    // 
    sqlite3* openDatabase(const char* dbName)
    {
        sqlite3 *db; // pointer to sqlite3
        int rc = sqlite3_open(dbName,&db); // assigns rc to sqlite3_open function
        if(rc) { // checks if sqlite cannot open
            std::cerr << "Cant open database" << sqlite3_errmsg(db) << std::endl;
            return nullptr;
        } else {
            std::cout << "Opened databsae successfully!" << std::endl;
            return db;
        }
    }

    void createTable(sqlite3* db)
    {
        const char* createTableSQL = "CREATE TABLE IF NOT EXISTS contacts ("
                                 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "Name TEXT, "
                                 "Company TEXT, "
                                 "Pin INTEGER, "
                                 "Safeword TEXT, );";
        char* errMsg = 0;
        int rc = sqlite3_exec(db, createTableSQL, nullptr, 0, &errMsg);
        if(rc != SQLITE_OK) {
            std::cerr << "SQL error:" << errMsg << std::endl;
            sqlite3_free(errMsg);
        } else {
           std::cout << "Table created successfully" << std::endl; 
        }
    }
    void insertContact(sqlite3* db, const char* Name, const char* Company, int pin, const char* safeword)
    {
        char* errMsg = 0;
         std::string insertSQL = "INSERT INTO contacts (first_name, last_name, birth_year, email, phone_number) VALUES ('" +
            std::string(Name) + "', '" + std::string(Company) + "', " + std::string(safeword) + ", '" +
            std::to_string(pin) + "');";
        int rc = sqlite3_exec(db, insertSQL.c_str(), nullptr, 0, &errMsg);
        if(rc != SQLITE_OK)
        {
            std::cerr << "SQL errror:" << errMsg << std::endl;
            sqlite3_free(errMsg);
        } else {
            std::cout << "Contact added successfully!" << std::endl;
        }
    } 
    void readContacts(sqlite3* db)
    {
        const char* selectSQL = "SELECT * FROM contacts;";
        char* errMsg = 0;
        int rc = sqlite3_exec(db, selectSQL, callback, 0, &errMsg);
        if(rc != SQLITE_OK)
        {
            std::cerr << "SQL ERROR: "<< errMsg << std::endl;
            sqlite3_free(errMsg);
        } else {
            std::cout << "Contacts fetched successfully!" << std::endl;
        }
    }      
};

int main()
{
    int choice;

    std::cout << "-=====- MENU -=====-\n"
              << "1. Choose database\n"
              << "2. ";



    return 0;
}