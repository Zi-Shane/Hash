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

int main(void) {
    string file_name;
    int hash_Table[100];
    int count = 0;
    int index = 0;
    
    cout << "file name: ";
    cin >> file_name;
    
    //read and open file
    ifstream file ( file_name , ifstream::in );
    //file open failed
    if (!file) {
        cout << "An error occured when opening file!";
        return EXIT_FAILURE;
    }
    //file open successed
    while (file >> hash_Table[index]) {
        count++;
        index++;
    }
    file.close();

    
    return EXIT_SUCCESS;
}
