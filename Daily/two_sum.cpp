// Daily/TwoSum.cpp
// Problem: Given an array of integers, return indices of the two numbers such that they add up to a target.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++){
        int complement = target - nums[i];
        if(mp.count(complement)) return {mp[complement], i};
        mp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto res = twoSum(nums, target);
    cout << res[0] << " " << res[1] << endl; // Output: 0 1
}
