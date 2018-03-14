#include<iostream>
#include<map>
// need climits for INT_MAX
#include<climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    // number, id and count
    map<int, pair<int, int>> num;

    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        num[temp].first = i;
        num[temp].second += 1;
    }
    int id = INT_MAX;
    int answer;
    for(auto &x: num) {
        if(x.second.second == 1 && id > x.second.first) {
            id = x.second.first;
            answer = x.first;
        }
    }
    if(id == INT_MAX) {
        cout << "None" << endl;
    }
    else {
        cout << answer << endl;
    }
    return 0;
}
