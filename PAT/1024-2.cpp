#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void add(string& s1, string& s2) {
    int flag = 0;
    for(int i = s1.length()-1; i >= 0; i--) {
        s1[i] += s2[i] - '0' + flag;
        flag = 0;
        if(s1[i] > '9') {
            s1[i] -= 10;
            flag = 1;
        }
    }
    if(flag) {
        s1 = '1' + s1;
    }
}

int main() {
    string N;
    int K;
    cin >> N >> K;

    int i = 0;
    for(; i < K; i++) {
        string num2 = N;
        reverse(num2.begin(), num2.end());
        if(num2 == N) {
            break;
        }
        add(N, num2);
    }

    cout << N << endl;
    cout << i << endl;
    return 0;
}
