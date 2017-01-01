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


    int hash_Table[table_size(count_items)];
    
    // push into hash table
    for (int i = 0; i < count_items; i++) {
        hash_Table[i] = file_items[i];
    }

//      Debug

//    //check table size
//    cout << sizeof(hash_Table) / sizeof(*hash_Table);
    
//    //print
//    for (int i = 0; i < count_items; i++) {
//        cout << hash_Table[i] << endl;
//    }
    
    return EXIT_SUCCESS;
}
