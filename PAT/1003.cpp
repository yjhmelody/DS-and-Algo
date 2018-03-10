#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

struct line {
    int c1;
    int c2;
    int len;
};

int main() {
    int N;
    int M;
    int C1;
    int C2;
    cin >> N >> M >> C1 >> C2;
    vector<int> numbers;
    while(N--) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    vector<line> lines;
    while(M--) {
        line city_line;
        cin >> city_line.c1 >> city_line.c2 >> city_line.len;
        lines.push_back(city_line);
    }


    return 0;
}
