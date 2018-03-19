#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> exits(N+1);
    int sum = 0;
    exits.at(0) = 0;
    for(auto it = exits.begin()+1; it != exits.end(); it++) {
        cin >> *it;
        sum += *it;
        *it = sum;
    }

    int M;
    cin >> M;
    while(M--) {
        int x;
        int y;
        cin >> x >> y;
        if(x > y) {
            swap(x, y);
        }
        int dis = exits.at(y-1) - exits.at(x-1);
        int dis2 = sum - dis;
        if(dis < dis2) {
            cout << dis << endl;
        }
        else {
            cout << dis2 << endl;
        }
    }

    return 0;
}
