#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

bool is_prime(int n) {
    if(n <= 1) {
        return false;
    }
    int max = int(sqrt(n));
    for(int i = 2; i <= max; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    int D;
    while(cin >> N && N >= 0) {
        cin >> D;
        if(!is_prime(N)) {
            cout << "No" << endl;
            continue;
        }
        vector<int> num;
        do{
            num.push_back(N % D);
            N /= D;
        }while(N);
        int sum = 0;
        for(auto &x: num) {
            sum = sum * D + x;
        }
        if(is_prime(sum)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
