#include<iostream>
#include<string>

using namespace std;

int main() {
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);

    for(auto it1 = s1.begin(); it1 != s1.end(); it1++) {
        bool flag = true;
        for(auto it2 = s2.cbegin(); it2 != s2.cend(); it2++) {
            if(*it1 == *it2) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << *it1;
        }
    }
    cout << endl;
    return 0;
}
