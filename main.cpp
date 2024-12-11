#include <iostream>
#include <unordered_map>
#include <stack>
#include <stdexcept>

using namespace std;

class InMemoryDB {
private:
    unordered_map<string, int> mainState;
    unordered_map<string, int> transactionState;
    bool transactionInProgress = false;

public:
    int get(const string& key) {
        if (transactionInProgress && transactionState.count(key)) {
            return transactionState[key];
        }
        if (mainState.count(key)) {
            return mainState[key];
        }
        throw runtime_error("Key not found");
    }

    void put(const string& key, int val) {
        if (!transactionInProgress) {
            throw runtime_error("No transaction in progress");
        }
        transactionState[key] = val;
    }

    void begin_transaction() {
        if (transactionInProgress) {
            throw runtime_error("A transaction is already in progress");
        }
        transactionInProgress = true;
        transactionState.clear();
    }

    void commit() {
        if (!transactionInProgress) {
            throw runtime_error("No transaction in progress to commit");
        }
        for (const auto& [key, value] : transactionState) {
            mainState[key] = value;
        }
        transactionInProgress = false;
        transactionState.clear();
    }

    void rollback() {
        if (!transactionInProgress) {
            throw runtime_error("No transaction in progress to rollback");
        }
        transactionInProgress = false;
        transactionState.clear();
    }
};

int main() {
    InMemoryDB db;

    try {
        // Test cases as per assignment examples
        try {
            db.get("A");
        } catch (const runtime_error& e) {
            cout << "A: null" << endl;
        }

        try {
            db.put("A", 5);
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }

        db.begin_transaction();
        db.put("A", 5);

        try {
            db.get("A");
        } catch (const runtime_error& e) {
            cout << "A: null" << endl;
        }

        db.put("A", 6);
        db.commit();

        cout << "A: " << db.get("A") << endl;

        try {
            db.commit();
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }

        try {
            db.rollback();
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }

        try {
            db.get("B");
        } catch (const runtime_error& e) {
            cout << "B: null" << endl;
        }

        db.begin_transaction();
        db.put("B", 10);
        db.rollback();

        try {
            db.get("B");
        } catch (const runtime_error& e) {
            cout << "B: null" << endl;
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
