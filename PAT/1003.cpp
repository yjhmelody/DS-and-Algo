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

    vector<int> dis(N, INT_MAX); // �ӳ����㵽i������·����·������
    vector<int> road_num(N); // �ӳ����㵽i������·��������
    vector<int> team_num(N); // �ӳ����㵽i���Ԯ�ӵ���Ŀ֮��
    vector<bool> visited(N, false);

    // ��ͱ߶���Ȩ�ص��ڽӱ�
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
        // �Ӿ���������ٵ㿪ʼ
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
        // ��u��ʼ����
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
                    // �����Ԯ�Ӹ������
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
