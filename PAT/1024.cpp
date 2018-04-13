#include<iostream>
#include<vector>
#include<string>

using namespace std;

//会溢出
template<typename T>
T get_reverse(T num) {
    T sum = 0;
    while(num) {
        sum = sum * 10 + num % 10;
        num /= 10;
    }
    return sum;
}

template<typename T>
bool is_palindromic(T num) {
    bool flag = true;
    T num2 = get_reverse(num);
    while(num != 0 && num2 != 0) {
        if(num % 10 != num2 % 10) {
            flag = false;
            break;
        }
        num /= 10;
        num2 /= 10;
    }
    return flag;
}

int main() {
    long long N;
    int K;

    cin >> N >> K;
    int i = 0;
    for(;i < K; i++) {
        if(is_palindromic(N)) {
            break;
        }

        N += get_reverse(N);
    }

    cout << N << endl;
    cout << i << endl;
    return 0;
}
