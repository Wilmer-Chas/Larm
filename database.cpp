#include "database.h"

// Open database
Database::Database(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    } else {
        std::cout << "Database connection established." << std::endl;
    }
}
// Close database (deconstruct)
Database::~Database() {
    if (db) {
        sqlite3_close(db);
        std::cout << "Database connection closed." << std::endl;
    }
}

// Error handling
bool Database::executeSQL(const std::string& sql) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
// Create new table
bool Database::createTable() {
    const std::string sql = R"(
        CREATE TABLE IF NOT EXISTS Customers (
            ID INTEGER PRIMARY KEY,
            Name TEXT NOT NULL,
            Company TEXT NOT NULL,
            SafeWord TEXT NOT NULL,
            Pin INTEGER NOT NULL
        );
    )";
    return executeSQL(sql);
}

bool Database::addCustomer(const Customer& customer) {
    const char* sql = R"(
        INSERT INTO Customers (ID, Name, Company, SafeWord, Pin)
        VALUES (?, ?, ?, ?, ?);
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, customer.getId());
    sqlite3_bind_text(stmt, 2, customer.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, customer.getCompany().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, customer.getSafeWord().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, customer.getPin());

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return success;
}

std::optional<Customer> Database::getCustomerById(int id) {
    const char* sql = "SELECT * FROM Customers WHERE ID = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return std::nullopt;
    }

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        Customer customer(
            sqlite3_column_int(stmt, 0),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)),
            sqlite3_column_int(stmt, 4)
        );
        sqlite3_finalize(stmt);
        return customer;
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}

bool Database::updateCustomer(const Customer& customer) {
    const char* sql = R"(
        UPDATE Customers
        SET Name = ?, Company = ?, SafeWord = ?, Pin = ?
        WHERE ID = ?;
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    
    sqlite3_bind_text(stmt, 1, customer.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, customer.getCompany().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, customer.getSafeWord().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, customer.getPin());
    sqlite3_bind_int(stmt, 5, customer.getId());

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return success;
}

bool Database::deleteCustomer(int id) {
    const char* sql = "DELETE FROM Customers WHERE ID = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, id);
    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return success;
}

std::vector<Customer> Database::getAllCustomers() {
    std::vector<Customer> customers;
    const char* sql = "SELECT * FROM Customers;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return customers;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        customers.emplace_back(
            sqlite3_column_int(stmt, 0),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)),
            sqlite3_column_int(stmt, 4)
        );
    }

    sqlite3_finalize(stmt);
    return customers;
}
