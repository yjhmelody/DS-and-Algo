#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

struct node {
    string addr;
    char data;
    string next;
};

int main() {
    int N;
    string addr1;
    string addr2;
    cin >> addr1 >> addr2 >> N;
    map<string, node> words;

    for (int i = 0; i < N; i++) {
        node x;
        cin >> x.addr >> x.data >> x.next;
        string addr = x.addr;
        words[addr] = x;
    }

    int count1 = 0;
    int count2 = 0;

    for(auto cur = addr1; cur != "-1"; cur = words[cur].next) {
        count1++;
    }

    for(auto cur = addr2; cur != "-1"; cur = words[cur].next) {
        count2++;
    }
    int diff = count1 - count2;
    if (diff > 0) {
        for(; diff--; addr1 = words[addr1].next);
    } else {
        for(; diff++; addr2 = words[addr2].next);
    }

    for(; addr1 != addr2;) {
        addr1 = words[addr1].next;
        addr2 = words[addr2].next;
    }
    if (words[addr1].next == "-1" && words[addr2].next == "-1") {
        cout << "-1" << endl;
    } else {
        cout << addr1 << endl;
    }
}
