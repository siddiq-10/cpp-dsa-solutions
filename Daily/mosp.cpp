// Minimum Operations to Sort a Permutation
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // Find the position of 0
        int zero = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }
        // Check whether values increase while
        // moving around the array in a direction
        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;

                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };
        int ans = INT_MAX;
        // Increasing direction: move right
        if (check(1)) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }
        // Increasing direction: move left
        if (check(-1)) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
    Solution test;
    vector<int> nums={1,0,2};
    int result=test.minOperations(nums);
    cout<<"Result: "<<result<<endl;
    return 0;
}
