#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int num;
    cin >> num;
    int num2 = sqrt(num);
    for(int k = 12; k >= 1; k--) {
        for(int i = 2; i <= num2; i++) {
            int acc = 1;
            for(int j = i; j < i+k; j++) {
                acc *= j;
            }
            if(num % acc == 0) {
                cout << k << endl;
                for(int j = 0; j < k-1; j++) {
                    cout << i+j << '*';
                }
                cout << i + k - 1 << endl;
                return 0;
            }
        }
    }

    cout << "1\n" << num << endl;
    return 0;
}
