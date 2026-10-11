// Sum of Squares of Special Elements
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution{
public:
    int ssse(vector<int> nums){
        int result=0;
        int n=nums.size();
        for (int i=1; i<=n; i++){
            if (n%i==0){
                result+=pow(nums[i-1],2);
            }
        }
        return result;
    }
};

int main(){
    Solution test;
    vector<int> nums1={2,7,1,19,18,3};
    int result=test.ssse(nums1);
    cout<<"Result: "<<result<<endl;
    return 0;
}
