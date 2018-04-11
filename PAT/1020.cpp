#include<iostream>
#include<vector>

using namespace std;
//
//因为后序的最后一个总是根结点，令i在中序中找到该根结点，
//则i把中序分为两部分，左边是左子树，右边是右子树。
//因为是输出先序（根左右），所以先打印出当前根结点，
//然后打印左子树，再打印右子树。左子树在后序中的根结点为
//root – (end – i + 1)，即为当前根结点-右子树的个数。
//左子树在中序中的起始点start为start，末尾end点为i – 1.
//右子树的根结点为当前根结点的前一个结点root – 1，
//右子树的起始点start为i+1，末尾end点为end。

struct node {
    node* left;
    node* right;
    int num;
};

void pre(int parent, int start, int end, int index, vector<int>& post_order, vector<int>& in_order, vector<int> & level_order) {
    if(start > end) {
        return;
    }
    int i = start;
    for(;i < end && in_order[i] != post_order[parent]; i++);
    level_order[index] = post_order[parent];
    pre(parent - 1 - end + i, start, i-1, 2 * index + 1, post_order, in_order, level_order);
    pre(parent - 1, i+1, end, 2 * index + 2, post_order, in_order, level_order);
}

int main() {
    int N;
    cin >> N;
    vector<int> post_order(N);
    vector<int> in_order(N);
    // 退化成线性会很大，所以要开大数组
    vector<int> level_order(10000, -1);

    for(auto &x: post_order) {
        cin >> x;
    }
    for(auto &x: in_order) {
        cin >> x;
    }

    pre(N-1, 0, N-1, 0, post_order, in_order, level_order);
    int count = 1;
    cout << level_order[0];
    for(int i = 1; i < level_order.size(); i++) {
        if(level_order[i] != -1) {
            count++;
            cout << " " << level_order[i];
            if(count == N) {
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
