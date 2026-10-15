// Subarray Distinct Element Sum of Squares |
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
public:
    int sdess(vector<int> nums){
        int result=0;
        for (int i=0; i<nums.size(); i++){
            unordered_set<int> st;
            for (int j=i; j<nums.size(); j++){
                st.insert(nums[j]);
                int dist=st.size();
                result+=dist*dist;
            }
        }
        return result;
    }
};

int main(){
    Solution test;
    vector<int> nums={1,2,1};
    int result=test.sdess(nums);
    cout<<"Result: "<<result<<endl;
    return 0;
}