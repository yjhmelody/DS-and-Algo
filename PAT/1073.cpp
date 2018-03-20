#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main() {
    string num1;
    string num2;
    cin >> num1;
    if(num1.at(0) == '-') {
        num2.push_back('-');
    }
    int E = num1.find('E');
    int exponent = stoi(num1.substr(E+1));
    // when meet E0
    // The segments code has no effort to the answer
    // But I can not pass one answer
    if(exponent == 0) {
        if(num1.at(0) == '-') {
            cout << num1.substr(0, E) << endl;
        }
        else {
            cout << num1.substr(1, E-1) << endl;
        }
        return 0;
    }
    for(int i = 0; i < -exponent; i++) {
        num2.push_back('0');
        if(i == 0) {
            num2.push_back('.');
        }
    }
    for(int i = 1; i < E; i++) {
        if(num1.at(i) != '.') {
            num2.push_back(num1.at(i));
            exponent--;
        }
    }
    for(int i = 0; i < exponent+1; i++) {
        num2.push_back('0');
    }

    cout << num2 << endl;
    return 0;
}
