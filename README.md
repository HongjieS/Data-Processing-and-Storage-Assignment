# Data-Processing-and-Storage-Assignment
The database provides the following functionalities:

begin_transaction(): Starts a new transaction.

put(key, value): Adds or updates a key-value pair during an active transaction.

get(key): Retrieves the value of a key.

commit(): Saves all changes made in the transaction to the main state.

rollback(): Discards all changes made in the transaction.

Steps to Run the Code

Clone or download the project files.

Navigate to the directory containing the main.cpp file.

Compile the code using a C++ compiler. For example, with g++:
g++ -std=c++17 -o in_memory_db main.cpp

Run the compiled program:
./in_memory_db

Future Improvements for Official Assignment

Make Inputs and Outputs Clear: Explain exactly how functions like get() should behave. For example, should they return null or print a message if the key doesn’t exist? This will help avoid confusion.

Better Error Handling: Add details about what should happen if someone tries to use put(), commit(), or rollback() without starting a transaction. This will make the program easier to use and debug.

Allow More Transactions: Add features so the program can handle more than one transaction at a time, or let transactions happen inside other transactions. This would make it more like a real-world database.

Add More Features: Include new options, like deleting a key, listing all the keys, or saving the database to a file so it doesn’t disappear when the program closes. These features would make the program more useful.

Make Grading Easier: Create test scripts or examples that graders can use to quickly check if the program works correctly, even for edge cases.
