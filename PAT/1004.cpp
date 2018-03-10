#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

struct node {
    string id;
    vector<node*> children;
};

void traverse(node* tree, int depth, vector<int>& counts) {
    if (depth >= counts.size()) {
            counts.push_back(0);
        }
    if(tree->children.size() == 0) {
        counts.at(depth) += 1;
    }
    for(auto child: tree->children) {
        traverse(child, depth+1, counts);
    }
}

node* search(node* tree, string& id) {
    if(tree && tree->id == id) {
        return tree;
    }
    for(auto child: tree->children) {
        return search(child, id);
    }
    return nullptr;
}

/**
    4 2
    01 2 02 03
    02 1 04

    0 1 1

    6 4
    01 2 02 03
    02 1 04
    04 1 05
    05 1 06

    0 1 0 0 1
*/

int main() {
    int N;
    int M;
    cin >> N >> M;
    int n = N;
    int m = M;
    node* root = new node();
    root->id = "01";
    while(M--) {
        string id;
        cin >> id;
        node* parent = search(root, id);
        if(parent == nullptr) {
            parent = new node();
            parent->id = id;
        }
        int K;
        cin >> K;
        while(K--) {
            node* child = new node();
            cin >> child->id;
            parent->children.push_back(child);
        }
    }
    vector<int> counts(2);
    traverse(root, 0, counts);
    int sum = 0;
    for(auto it = counts.cbegin(); it != counts.cend()-1; it++) {
        cout << *it << " ";
        sum += *it;
    }
    sum += *(counts.cend()-1);
    cout << *(counts.cend()-1) << endl;
//    cout << "M:"<<m<<"N:"<< n << "sum:"<<sum<<endl;
    delete root;
    return 0;
}
