// 2089 Find Target Indices After Sorting Array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> ti(vector<int> nums, int target){
        vector<int> result;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==target){
                result.push_back(i);
            }
        }
        return result;
    }

};

int main(){
    Solution test;
    vector<int> nums={1,2,5,2,3};
    int target=2;
    vector<int> result=test.ti(nums,target);
    for (int i=0; i<result.size(); i++){
        cout<<"> "<<result[i]<<endl;
    }
    return 0;
}