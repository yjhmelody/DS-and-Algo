#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
//����������������������ж����м�����ͨ������
//����ж�����Ǿ����Error: x components�����ֻ��һ����
//��������������������ȴ�һ�����dfs������߸߶�ӵ�еĽ���ǣ�
//Ȼ�����Щ����е���������һ����ʼdfs�õ���߸߶ȵĽ���ǣ�
//��������㼯�ϵĲ�����������

int max_height = 0;
void dfs(int start, int height, vector<vector<int>>& graph, vector<bool>& visit, vector<int>& result) {
    // �����߶ȣ����ұ������߶ȵĽڵ�
    if(height > max_height) {
        result.clear();
        result.push_back(start);
        max_height = height;
    }
    else if(height == max_height) {
        result.push_back(start);
    }

    visit[start] = true;
    for(auto &x: graph[start]) {
        if(visit[x] == false) {
            dfs(x, height+1, graph, visit, result);
        }
    }
}

int main() {
    int N;
    cin >> N;
    // �ڽ�����
    vector<vector<int>> graph(N+1);
    vector<bool> visit(N+1, false);
    vector<int> result;

    for(int i = 0; i < N - 1; i++) {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 0;
    for(int i = 1; i < graph.size(); i++) {
        if(visit[i] == true) {
            continue;
        }
        dfs(i, 1, graph, visit, result);
        count++;
    }
    if(count >= 2) {
        printf("Error: %d components", count);
        return 0;
    }
    set<int> nodes;
    nodes.insert(result.begin(), result.end());
    max_height = 0;
    fill(visit.begin(), visit.end(), false);
    result.clear();
    dfs(*nodes.begin(), 1, graph, visit, result);
    nodes.insert(result.begin(), result.end());
    for(auto &x: nodes) {
        cout << x << endl;
    }
    return 0;
}
