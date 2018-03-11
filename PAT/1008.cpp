#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    int now = 0;
    int sum = n * 5;
    vector<int> nums(n);
    while(n--) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    for(auto num: nums) {
        // up
        if(now < num) {
            sum += (num - now) * 6;
        }
        // down
        else if(now > num) {
            sum += (now - num) * 4;
        }
        now = num;
    }
    cout << sum << endl;
    return 0;
}
