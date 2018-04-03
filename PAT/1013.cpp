#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

//添加的最少的路线，就是他们的连通分量数-1，
//因为当a个互相分立的连通分量需要变为连通图的时候，
//只需要添加a-1个路线，就能让他们相连。
//所以这道题就是求去除了某个结点之后其他的图所拥有的连通分量数

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
