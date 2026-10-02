#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
private: 
    void backtrack(vector<string>& result, string curr, int open_count, int close_count, int n){
        if (curr.length()==2*n){
            result.push_back(curr);
            return;
        }
        if (open_count<n){
            backtrack(result,curr+"(",open_count+1,close_count,n);
        }
        if (close_count<open_count){
            backtrack(result,curr+")",open_count, close_count+1,n);
        }
    }
public:
    vector<string> generate_parenthesis(int n){
        vector<string> result;
        string curr;
        int open_count=0;
        int close_count=0;
        backtrack(result,curr,open_count,close_count,n);
    }
};

int main(){
    Solution Test3;
    vector<string> result=Test3.generate_parenthesis(3);
    for (int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}