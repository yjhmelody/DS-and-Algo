#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    string num;
    cin >> num;
    int flag = 0;
    vector<int> counts(10, 0);
    for(auto it = num.rbegin(); it != num.rend(); it++) {
        int temp = *it - '0';
        counts[temp]++;
        temp = temp * 2 + flag;
        flag = 0;
        if(temp >= 10) {
            temp -= 10;
            flag = 1;
        }
        *it = temp + '0';
        counts[temp]--;
    }

    bool flag2 = true;
    for(auto count: counts) {
        if(count != 0) {
            flag2 = false;
        }
    }

    if(flag2 && flag == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    if(flag == 1) {
        cout << "1";
    }
    for(auto s: num){
        cout << s;
    }
    cout << endl;
    return 0;
}
