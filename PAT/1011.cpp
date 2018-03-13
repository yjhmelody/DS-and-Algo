#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main() {
    const char* str = "WTL";
    vector<vector<double>> games(3);
    vector<pair<int, double>> maximum(3, pair<int, double>(0,0));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            double num;
            cin >> num;
            games[i].push_back(num);
            if(maximum[i].second < num) {
                maximum[i].second = num;
                maximum[i].first = j;
            }
        }
    }

    double sum = 1.0;
    for(auto &val: maximum) {
        cout << str[val.first] << " ";
        sum *= val.second;
    }
    printf("%.2f", (sum * 0.65 - 1) * 2);
    return 0;
}
