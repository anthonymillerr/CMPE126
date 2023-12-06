#include <iostream>     // Include necessary libraries for input and output
#include <vector>       // Include the vector library for dynamic arrays
#include <string>       // Include the string library for string manipulation

using namespace std;

class HashTable {
private:
    int size;           // Size of the hash table
    vector<int> table;  // Vector to store the hash table

public:
    // Constructor to initialize the hash table with a given size and fill it with -1 (empty)
    HashTable(int m) {
        size = m;                          // Set the size of the hash table
        table.resize(size, -1);            // Resize the table vector and fill with -1 (indicating empty slots)
    }

    // Hash function to calculate the index in the hash table for a given key
    int hashFunction(int key) {
        return key % size;                  // Simple modulo operation to get the index
    }

    // Function to insert a key into the hash table using linear probing for collision resolution
    bool insertKey(int key) {
        int index = hashFunction(key);      // Get the initial index for the key

        while (table[index] != -1) {        // Handle collisions using linear probing
            index = (index + 1) % size;     // Move to the next index
            if (index == hashFunction(key)) {
                                            // The hash table is full
                return false;               // Return false indicating failure to insert
            }
        }
        table[index] = key;                  // Insert the key at the calculated index
        // Key has been inserted successfully, return true
        return true;
    }

    // Function to retrieve the index of a key from the hash table
    int retrieveKey(int key) {
        int index = hashFunction(key);      // Get the initial index for the key

        while (table[index] != -1) {        // Search for the key using linear probing
            if (table[index] == key) {
                                            // Key found, return its index
                return index;
            }
            index = (index + 1) % size;      // Move to the next index
        }

        // Key not found, return -1
        return -1;
    }

    // Function to print the hash table
    void printHashTable() {
        bool isEmpty = true;                 // Flag to check if the hash table is empty
        cout << "\n";
        for (int i = 0; i < size; ++i) {
            if (table[i] != -1) {
                cout << table[i];              // Print the value at the index if not empty
                isEmpty = false;               // The table is not empty
            } else {
                cout << "-";                   // Print a dash if the index is empty
            }

            if (i < size - 1) {
                cout << ", ";                  // Add a comma and space for better readability
            }
        }

        if (isEmpty) {
            cout << "\n\nThe Hash Table Is Empty!";  // Print a message if the table is empty
        }

        cout << endl;
    }
};

int main() {
    int m;
    cout << "Please Enter m (Size Of Hashtable): ";
    cin >> m;

    HashTable hashTable(m);  // Create a hash table with the specified size

    char choice;
    int key, index;  // Move the declaration outside the switch

    do {
        cout << "\nChoose An Input:\n\n- I<key> (Insert)\n\n- R<key> (Retrieve)\n\n- P (Print)\n\n- E (Exit)\n\n";
        cin >> choice;

        switch (choice) {
            case 'I':
                cin >> key;
                if (hashTable.insertKey(key)) {
                    cout << "\nKey Has Been Inserted!" << endl;  // Print message if key has been inserted
                } else {
                    cout << "\nThe Hash Table Is Full!" << endl;  // Print message if the table is full
                }
                break;
            case 'R':
                cin >> key;
                index = hashTable.retrieveKey(key);  // Use the variable outside the switch
                if (index != -1) {
                    cout << "\nKey " << key << " Found At Index: " << index << endl;  // Print index if key is found
                } else {
                    cout << "\nThe Key Was Not Found" << endl;  // Print message if key is not found
                }
                break;
            case 'P':
                hashTable.printHashTable();  // Print the entire hash table
                break;
            case 'E':
                cout << "\nExiting Program" << endl;  // Exit the program
                break;
            default:
                cout << "\nInvalid Choice" << endl;  // Print message for invalid input
        }
    } while (choice != 'E');  // Continue the loop until the user chooses to exit

    return 0;  // Return 0 to indicate successful program execution
}

/*Please Enter m (Size Of Hashtable): 10

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I25

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I17

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

R25

Key 25 Found At Index: 5

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

R17

Key 17 Found At Index: 7

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

R56

The Key Was Not Found

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I45

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I36

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

P

-, -, -, -, -, 25, 45, 17, 36, -

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I40

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I50

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I70

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I18

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I29

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I37

Key Has Been Inserted!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

I77

The Hash Table Is Full!

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)

R37

Key 37 Found At Index: 4

Choose An Input:

- I<key> (Insert)

- R<key> (Retrieve)

- P (Print)

- E (Exit)
*/