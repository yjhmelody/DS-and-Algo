#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>

using namespace std;

struct line {
    int c1;
    int c2;
    int len;
};


int main() {
    int N; // point count
    int M; // edge count
    int C1; // start point
    int C2; // end point
    cin >> N >> M >> C1 >> C2;

    vector<int> dis(N, INT_MAX); // 从出发点到i结点最短路径的路径长度
    vector<int> road_num(N); // 从出发点到i结点最短路径的条数
    vector<int> team_num(N); // 从出发点到i点救援队的数目之和
    vector<bool> visited(N, false);

    // 点和边都带权重的邻接表
    vector<pair<int, vector<line>>> cities(N);
    // cin
    for(auto &x: cities) {
        cin >> x.first;
    }

    for(int i = 0;i < M; i++) {
        int c1;
        int c2;
        int len;
        cin >> c1 >> c2 >> len;
        cities[c1].second.push_back({c1, c2, len});
    }
    // end cin

    dis[C1] = 0;
    team_num[C1] = cities[C1].first;
    road_num[C1] = 1;
    for(int i = 0; i < N; i++) {
        int u = -1;
        int min = INT_MAX;
        // 从距离最近的临点开始
        for(int j = 0; j < N; j++) {
            if(visited[j] == false && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if(u == -1) {
            break;
        }
        visited[u] = true;
        // 从u开始出发
        for(auto &x: cities[u].second) {
            int &v = x.c2;
            if(visited[v] == false) {
                int temp = dis[u] + x.len;
                if(temp < dis[v]) {
                    dis[v] = temp;
                    road_num[v] = road_num[u];
                    team_num[v] = team_num[u] + cities[v].first;
                }
                else if(dis[u] + x.len == dis[v]) {
                    road_num[v] = road_num[u] + road_num[v];
                    // 如果救援队个数变多
                    int temp = team_num[u] + cities[v].first;
                    if(temp > team_num[v]) {
                        team_num[v] = temp;
                    }
                }
            }
        }
    }

    cout << road_num[C2] << " " << team_num[C2] << endl;

//     check
//    for(auto &x: cities) {
//        cout << x.first << " ";
//        for(auto &y: x.second) {
//            cout << y.c1 << " " << y.c2 << " " << y.len << endl;
//        }
//    }
    return 0;
}
