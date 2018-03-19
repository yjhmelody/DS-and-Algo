#include<cstdio>
#include<unordered_map>
#include<map>
using namespace std;

int main() {
    int M;
    int N;
    scanf("%d %d", &M, &N);
    int half = M * N / 2;
    // map is better than unordered_map in this problem
    map<int, int> counts;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int x;
            // strict time
            // please use cstdio
            scanf("%d", &x);
            counts[x]++;
            if(counts[x] > half) {
                printf("%d\n", x);
                return 0;
            }
        }
    }
}

