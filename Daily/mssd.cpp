// Minimum Sum of Squared Difference ~ reducing a difference by 1 gives a greater benefit when the difference is larger.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    long long mssd(vector<int> nums1, vector<int> nums2, int k1, int k2){

    }
};

int main(){
    Solution test;
    vector<int> nums1={1,4,10,12};
    vector<int> nums2={5,8,6,9};
    int k1=1;
    int k2=1;
    long long result=test.mssd(nums1, nums2, k1, k2);
    cout<<"Result: "<<result<<endl;                     // 43
    return 0;
}