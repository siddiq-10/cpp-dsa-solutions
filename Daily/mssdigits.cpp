// Maximum Sum of Squares of Digits
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string mssd(int num , int sum){
        string result="";
        if(1LL*num*9<sum){
            return result;
        }
        if (sum>0){
            result+=('0'+sum);
        }
        if (result.size()<num){
            result+='0';
        }
        return result;
    }
};

int main(){
    Solution test;
    int num=2;
    int sum=3;
    string result=test.mssd(num, sum);
    cout<<"Result:"<<result<<endl;
    
}