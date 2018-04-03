#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

// 去掉的点的临近点中只有一条边的个数

// node is from 0 to n-1
void dfs(int node, vector<vector<bool>>& edges, vector<bool>& visit) {
    visit[node] = true;
    for(int i = 0; i < visit.size(); i++) {
        // if it has not visited and there is a way
        if(visit.at(i) == false && edges.at(node).at(i) == true) {
            dfs(i, edges, visit);
        }
    }
}

int main() {
    int N;
    int M;
    int K;
    cin >> N >> M >> K;
    vector<vector<bool>> highways(N);
    vector<bool> visit(N);

    for(auto &x: highways) {
        x.resize(N);
    }

    for(int i = 0; i < M; i++) {
        int from;
        int to;
        cin >> from >> to;
        highways.at(from-1).at(to-1) = highways.at(to-1).at(from-1) = true;
    }

//    for(auto highway: highways) {
//        for(auto x: highway) {
//            cout << x << endl;
//        }
//    }

    for(int i = 0; i < K; i++) {
        // init
        fill(visit.begin(), visit.end(), false);

        int city;
        cin >> city;
        int count = 0;
        // destroyed
        visit[city-1] = true;
        for(int j = 0; j < N; j++) {
            if(visit[j] == false) {

                dfs(j, highways, visit);
                count++;
            }
        }
        cout << count-1 << endl;
    }
    return 0;
}
