#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstdio>

using namespace std;

int reorder(int num, bool is_inc = true, int n = 4) {
	vector<int> vec(n);
    for(auto &x: vec) {
   		x = num % 10;
        num /= 10;
    }
    if(is_inc) {
   		sort(vec.begin(), vec.end());
    }
    else {
   		sort(vec.begin(),vec.end(), greater<int>());
    }

    int sum = 0;
    for(auto &x: vec) {
   		sum = sum * 10 + x;
    }
    return sum;
}

int main() {
    int num;
    cin >> num;
    int a = reorder(num, false);
    int b = reorder(num, true);
    if(a == b) {
        cout << a << " - " << b << " = 0000";
   		return 0;
    }
    int c = num;
    do {
   		a = reorder(c, false);
        b = reorder(c, true);
        c = a - b;
   		printf("%04d - %04d = %04d\n", a, b, c);
    } while(c != 6174);
    return 0;
}
