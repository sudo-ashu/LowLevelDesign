#include <bits/stdc++.h>
using namespace std;

// Low-level module
class MySQLDatabase {  
public:
    void saveToSQL(string data) {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

// Low-level module
class MongoDBDatabase {  
public:
    void saveToMongo(string data) {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

// High-level module (Tightly coupled)
class UserService {  
private:
    MySQLDatabase sqlDb;  // Direct dependency on MySQL
    MongoDBDatabase mongoDb;  // Direct dependency on MongoDB

public:
    void storeUserToSQL(string user) {
        // MySQL-specific code
        sqlDb.saveToSQL(user);  
    }

    void storeUserToMongo(string user) {
        // MongoDB-specific code
        mongoDb.saveToMongo(user);  
    }
};

int main() {
    UserService service;
    service.storeUserToSQL("Ashutosh");
    service.storeUserToMongo("Mahender");
    
    return 0;
}