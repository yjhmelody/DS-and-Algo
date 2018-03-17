#include<iostream>
#include<string>
#include<vector>

using namespace std;

//012345678901234567890123456789


int main() {
    int n13 = 1;
    int n2 = 3;
    string str;
    cin >> str;
    int N = str.size();
    for(int i = 3; i <= N; i++) {
        n13 = N + 2 - i;
        if(n13 & 2 != 0) {
            continue;
        }
        if(n13 <= i * 2) {
            n2 = i;
            break;
        }
    }
    for(int i = 0; i < n13/2 - 1; i++) {
        cout << str.at(i);
        for(int j = 1; j < n2-1; j++) {
            cout << " ";
        }
        cout << str.at(N-i-1) << endl;
    }
    for(int i = n13/2 - 1; i < n2 + n13/2-1; i++) {
        cout << str.at(i);
    }
    cout << endl;
    return 0;
}
