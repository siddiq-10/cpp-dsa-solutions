// Sum of Sortable Integers
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> prefDrop(n, 0);
        // Prefix maximum
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }
        // Suffix minimum
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }
        // Count adjacent descents
        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }
        int ans = 0;
        // Try every divisor k of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool valid = true;
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                // Descents inside this block
                int drops = prefDrop[end] - prefDrop[start];
                // Include circular wraparound
                if (nums[end] > nums[start]) {
                    drops++;
                }
                if (drops > 1 ||
                    prefMax[start] > suffMin[start]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans += k;
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> nums={3,1,2};
    int result=test.sortableIntegers(nums);
    cout<<"Result: "<<result<<endl;
    return 0;
}