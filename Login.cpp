//
// Created by 33559 on 2022/11/30.
//
#include "Login.h"
bool login()
{
    string manager = "ZHOU";
    string input_1;
    int password = 33559;
    int input_2;
    cout << " Account: ";
    cin >> input_1;
    cout << "Password: ";
    cin >> input_2;
    if(input_1 == manager && input_2 == password)
    {
        cout << "Login Successfully!" <<endl;
        return true;
    }
    else
    {
        cout << "Failed Again PLease!" <<endl;
    }
    return false;
}
//            cout << "Failed! You can try " << 3 - count << endl;