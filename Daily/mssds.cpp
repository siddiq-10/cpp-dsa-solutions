// Minumim Swap to Sort by Digit Sum
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
private:
    int digitsum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
private:
    void swap(vector<int> nums, int i, int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
public:
    int mssds(vector<int> nums){
        unordered_map<int, int> digisums;
        int swap=0;
        vector<int> sums;
        for (int digit: nums){
            sums.push_back(digitsum(digit));
        }
    }
};