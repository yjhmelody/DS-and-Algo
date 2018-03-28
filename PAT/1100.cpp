#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cctype>

using namespace std;

//tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou
map<int, pair<string, string>> earth_to_mars {
     {0, make_pair("tret", "tret")},
     {1, make_pair("jan", "tam")},
     {2, make_pair("feb", "hel")},
     {3, make_pair("mar", "maa")},
     {4, make_pair("apr", "huh")},
     {5, make_pair("may", "tou")},
     {6, make_pair("jun", "kes")},
     {7, make_pair("jly", "hei")},
     {8, make_pair("aug", "elo")},
     {9, make_pair("sep", "syy")},
     {10, make_pair("oct", "lok")},
     {11, make_pair("nov", "mer")},
     {12, make_pair("dec", "jou")}
};

int find_num(string & num) {
    for(auto &x: earth_to_mars) {
        if(x.second.first == num) {
            return x.first;
        }
        if(x.second.second == num) {
            return x.first * 13;
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    string temp;
    getline(cin, temp);
    vector<string> nums(N);
    for(auto &x: nums) {
        getline(cin, x);
    }

    for(auto &x: nums) {
        // earth
        if(isdigit(x.at(0))) {
            auto num = stoi(x);
            if(num < 13) {
                cout << earth_to_mars[num].first << endl;
            }
            else {
                auto digit1 = num % 13;
                auto digit2 = num / 13;
                if(digit1 == 0) {
                    cout << earth_to_mars[digit2].second << endl;
                    continue;
                }
                if(digit2 == 0) {
                    cout << earth_to_mars[digit1].first << endl;
                    continue;
                }
                cout << earth_to_mars[digit2].second << " " << earth_to_mars[digit1].first << endl;
            }
        }
        // mars
        else {
            if(x.size() > 6) {
                auto digit2 = x.substr(0, 3);
                auto digit1 = x.substr(4, 3);
                int s1 = find_num(digit1);
                int s2 = find_num(digit2);
                cout << s2 + s1 << endl;
            }
            else {
                cout << find_num(x) << endl;
            }
        }
    }
    return 0;
}
