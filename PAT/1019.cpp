#include<iostream>
#include<vector>

using namespace std;

int main() {
    long long N;
    long long b;
    cin >> N >> b;
    vector<long long> num;
    if(N == 0) {
        num.push_back(0);
    }
    while(N) {
        num.push_back(N % b);
        N /= b;
    }
    bool flag = true;
    for(int i = 0; i < num.size(); i++) {
        if(num[i] != num[num.size()-i-1]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    cout << *num.crbegin();
    for(auto it = num.crbegin() + 1; it != num.crend(); it++) {
        cout << " " << *it;
    }
    return 0;
}
