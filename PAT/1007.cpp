#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &x: nums) {
        cin >> x;
    }

    int sum = -1;
    int left = 0;
    int right = n-1;
    int temp_sum = 0;
    int temp_left = 0;

    for(int i = 0; i < n; i++) {
        temp_sum += nums[i];
        if(temp_sum < 0) {
            temp_sum = 0;
            temp_left = i+1;
        }
        else if(temp_sum > sum) {
            sum = temp_sum;
            left = temp_left;
            right = i;
        }
    }
    if(sum < 0) {
        sum = 0;
    }
    cout << sum << " " << nums[left] << " " << nums[right] << endl;
    return 0;
}
