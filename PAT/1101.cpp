#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 对原序列sort排序，逐个比较，当当前元素没有变化并且
// 它左边的所有值的最大值都比它小的时候就可以认为它一定是主元

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);

    for (auto &n : nums){
        cin >> n;
    }

    auto nums2 = nums;
    sort(nums2.begin(), nums2.end(), [](int a, int b) {
        return a < b ? true : false;
    });

    vector<int> pivots;
    int max = 0;
    for (auto it = nums.begin(), it2 = nums2.begin(); it2 != nums2.end(); it++, it2++){
        if (*it == *it2 && *it > max){
            pivots.push_back(*it);
        }
        if (*it > max){
            max = *it;
        }
    }

    cout << pivots.size() << endl;
    for (auto i = 0; i < pivots.size() - 1; i++){
        cout << pivots[i];
        cout << " ";
    }
    if (pivots.size() != 0){
        cout << pivots[pivots.size() - 1] << endl;
    } else {
        cout << endl;
    }
}
