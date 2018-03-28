#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    map<char, int> counts;
    for(auto x: s2) {
        counts[x]++;
    }

    for(auto x: s1) {
        counts[x]--;
    }
    bool flag = true;
    int count_more = 0;
    int count_less = 0;
    for(auto &x: counts) {
        if(x.second > 0) {
            flag = false;
            count_less += x.second;
        }
        else if(x.second < 0) {
            count_more -= x.second;
        }
    }

    if(flag) {
        cout << "Yes " << count_more << endl;
    }
    else {
        cout << "No " << count_less << endl;
    }
    return 0;
}
