#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

int main() {
    string s1;
    string s2;
    string s3;
    cin >> s1;
    cin >> s2;

    for(auto &x: s1) {
        if(s2.find(x) == string::npos && s3.find(toupper(x)) == string::npos) {
            s3.push_back(toupper(x));
        }
    }
    cout << s3 << endl;
    return 0;
}
