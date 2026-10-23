// Maximum K to Sort a Permutation
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                k &= nums[i];
            }
        }

        return max(k, 0);
    }
};

int main(){
    Solution test;
    vector<int> nums={0,3,2,1};
    int result=test.sortPermutation(nums);
    cout<<"Result: "<<result<<endl;
    return 0;
}