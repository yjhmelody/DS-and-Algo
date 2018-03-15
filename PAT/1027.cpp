#include<iostream>
#include<vector>
#include<string>
#include<array>

using namespace std;
char ch[14] = {"0123456789ABC"};
char transform(int x) {
    return ch[x];
}

int main() {
    array<int, 3> rgb;
    array<string, 3> new_rgb = {"00", "00", "00"};
    for(auto &x: rgb) {
        cin >> x;
    }
    for(int i = 0; i < 3; i++) {
        char mod = transform(rgb[i] % 13);
        char div = transform(rgb[i] / 13);
        new_rgb[i][1] = mod;
        new_rgb[i][0] = div;
    }

    cout << '#';
    for(auto x: new_rgb) {
        cout << x;
    }
    cout << endl;
    return 0;
}
