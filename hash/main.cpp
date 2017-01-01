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

// determine table size
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
        
        if (isCollision(table, hashed))
            probing_times++;
        else
           // *probing_total += probing_times;
            return hashed;
    }
    return -1;    //probing failed
}
// print hashed table
void print_table(int *table, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Table[" << i << "]\t" << table[i] << endl;
    }
}

int main(void) {
    string file_name;
    int file_items[100];  // temp array to store the numbers, readed from input file
    int count_items = 0;      // count how many integer in the file
    
    cout << "file name: ";
    cin >> file_name;
    
    // read and open file
    ifstream file ( file_name , ifstream::in );
    // file open failed
    if (!file) {
        cout << "An error occured when opening file!";
        return EXIT_FAILURE;
    }
    // file open successed
    while (file >> file_items[count_items]) {
        count_items++;    // if reading not false -> next index
    }
    file.close();

    int size = table_size(count_items);
    int hash_Table[size];    // create a hash table
    for (int i = 0; i < size; i++) {
        hash_Table[i] = 0;
    }
    
//    int *probing_times_total = 0;
    
    for (int i = 0; i < count_items; i++) {
        int hashed_index = hash_function(file_items[i], size, hash_Table);
        if (hashed_index == -1)
            cout << "probing failed!" << hashed_index << endl;
        else
            hash_Table[hashed_index] = file_items[i];
    }
    
    print_table(hash_Table, size);
    
    
    
  //  cout << "\nTotal probing times = " << probing_times_total << endl;
    

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
