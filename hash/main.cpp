//
//  main.cpp
//  hash
//
//  Created by ZiShane on 2016/12/31.
//  Copyright © 2016年 ZiShane. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;
int probing_times_total = 0;

// determine table size (prime number)
int table_size(int items_num) {
    int size;    // table size
    items_num *= 2;
    
    int divisible = 0;    // divisible times
    int i;
    for (i = 1; i <= items_num; i++) {
        if (items_num % i == 0) {
            divisible++;
            if (divisible > 2) {
                items_num += 1;    // try next size
                divisible = 0;    // initial divisible times
                i = 0;        // initial start index (because ++ after for)
            }
        }
    }
    return size = --i;
}
// customer table size
int customer_size() {
    int size;
    cout << "Table size : ";
    cin >> size;
    cout << endl;
    return size;
}


// probing func
int probing_q(int i) {
    int probing = i * i;
    return probing;
}
// check collision
bool isCollision(int *table, int index){
    bool collision = true;
    return collision = (table[index] == 0 ? false : true);
}
// determine hashed value
int hash_function(int origin, int size, int *table, int probing_times = 0) {
    int hashed;
    
    while (probing_times < 100) {
        hashed = (origin + probing_q(probing_times)) % size;
        
        if (isCollision(table, hashed)) {
            probing_times++;
        } else {
            probing_times_total += probing_times;
            return hashed;
        }
    }
    return -1;    //probing failed
}
// print hashed table
void print_table(int *table,int table_size) {
    for (int i = 0; i < table_size; i++) {
        if (table[i] == 0) {
            cout << "Table[" << i << "]\t" << "-" << endl;
        } else {
            cout << "Table[" << i << "]\t" << table[i] << endl;
        }
    }
}


int main(void) {
    string file_name;
    int file_items[100];  // temp array to store the numbers, readed from input file
    int count_items = 0;      // count how many integer in the file
    
    cout << "This is a hash program" << endl;
    cout << "file name: ";
    cin >> file_name;
    
    // read and open file
    ifstream file ( file_name , ifstream::in );
    // file open failed
    if (!file) {
        cout << "An error occured when opening file!" << endl;
        return EXIT_FAILURE;
    }
    // file open successed
    while (file >> file_items[count_items]) {
        count_items++;    // if reading not false -> next index
    }
    file.close();

    int size;
    while (true) {
        int chose_func;
        cout << "----------------------------------" << endl;
        cout << "1. Automatically choose table size" << endl;
        cout << "2. Customer table size" << endl;
        cout << "Choose table size: ";
        cin >> chose_func;
        cout << "----------------------------------" << endl;
        
        if (chose_func == 1) {
                // auto choose size
                size = table_size(count_items);
                break;
        } else if (chose_func == 2) {
                // custom choose size
                size = customer_size();
                if (size < count_items) {
                    cout << "Please choose a bigger size" << endl;
                    return EXIT_FAILURE;
                }
                break;
        } else continue;
    }
    
    int hash_Table[size];    // create a hash table
    for (int i = 0; i < size; i++) {
        hash_Table[i] = 0;
    }
    
    for (int i = 0; i < count_items; i++) {
        int hashed_index = hash_function(file_items[i], size, hash_Table);
        if (hashed_index == -1)
            cout << "probing failed!" << hashed_index << endl;
        else
            hash_Table[hashed_index] = file_items[i];
    }
    
    print_table(hash_Table, size);
    
    cout << "\nTotal probing times = " << probing_times_total << endl;
    

//      Debug

//    // check how many items in hashed table & table size
//    cout << "\n";
//    int j = 0;
//    for (int i = 0; i < size; i++) {
//        cout << hash_Table[i] << ",";
//        if (hash_Table[i] != 0) {
//            j++;
//        }
//    }
//    cout << "\n" << j << "," << size;
    
//    // push into hash table
//    int hash_Table[table_size(count_items)];
//    for (int i = 0; i < count_items; i++) {
//        hash_Table[i] = file_items[i];
//    }
    
    
//    // check table size
//    cout << sizeof(hash_Table) / sizeof(*hash_Table);
    
//    // print read file
//    for (int i = 0; i < count_items; i++) {
//        cout << hash_Table[i] << endl;
//    }
    
    return EXIT_SUCCESS;
}
