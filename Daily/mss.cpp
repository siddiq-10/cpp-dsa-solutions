// Apply Operations on Array to Maximize Sum of Squares
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int mss(vector<int> nums, int k){
        const long long MOD = 1e9 + 7;
        vector<int> bitCount(31, 0);
        for (int num : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if (num & (1 << bit)) {
                    bitCount[bit]++;
                }
            }
        }
        long long ans=0;
        for (int i=0; i<k; i++){
            long long x=0;
            for (int bit=0; bit<31; bit++){
                if (bitCount[bit]>0){
                    x|=(1LL<<bit);
                    bitCount[bit]--;
                }
            }
            ans=(ans+x*x)%MOD;

        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> nums={2,6,5,8};
    int k=2;
    int result=test.mss(nums, k);
    cout<<"Result: "<<result<<endl;
    return 0;
}