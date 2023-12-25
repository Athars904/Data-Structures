#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    int bucketCount; // Number of buckets in the hash table
    std::vector<std::list<std::pair<int, std::string>>> table; // Hash table using vector of linked lists

    // Hash function
    int hashFunction(int key) {
        return key % bucketCount;
    }

public:
    // Constructor
    HashTable(int buckets) : bucketCount(buckets) {
        table.resize(bucketCount);
    }

    // Insert a key-value pair into the hash table
    void insert(int key, const std::string& value) {
        int index = hashFunction(key);
        for (const auto& kvp : table[index]) {
            if (kvp.first == key) {
                // Key already exists, update the value
                kvp.second = value;
                return;
            }
        }
        // Key does not exist, insert a new node
        table[index].push_back(std::make_pair(key, value));
    }

    // Search for a key in the hash table and return its corresponding value
    std::string search(int key) {
        int index = hashFunction(key);
        for (const auto& kvp : table[index]) {
            if (kvp.first == key) {
                // Key found, return the corresponding value
                return kvp.second;
            }
        }
        // Key not found
        return "Key not found";
    }

    // Delete a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                // Key found, remove the node
                table[index].erase(it);
                return;
            }
        }
    }
};

int main() {
    // Create a hash table with 10 buckets
    HashTable hashTable(10);

    // Insert some key-value pairs
    hashTable.insert(5, "Value 1");
    hashTable.insert(15, "Value 2");
    hashTable.insert(25, "Value 3");

    // Search for a key
    std::cout << "Value for key 15: " << hashTable.search(15) << std::endl;

    // Delete a key
    hashTable.remove(15);

    // Search again after deletion
    std::cout << "Value for key 15 after deletion: " << hashTable.search(15) << std::endl;

    return 0;
}
