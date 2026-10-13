// Maximum Alternating Sum of Squares
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int mass(vector<int> nums){
        vector<long long> squares;
        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }
        sort(squares.begin(), squares.end());
        int n = squares.size();
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans -= squares[i];
        }
        for (int i = n / 2; i < n; i++) {
            ans += squares[i];
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> nums={1,-1,2,-2,3,-3};
    int result=test.mass(nums);
    cout<<"Result: "<<result<<endl;
    return 0;
}