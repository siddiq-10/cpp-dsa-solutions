// Given a number N - generate all strings of length N using only the 'A' and 'B'
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
private:
    void bt_dfs(string s, vector<int> result, int n){
        if (s.size()==n){

        }
    }

public:
    vector<string> gen_str(int n){
        string s="ab";
        string temp_str;
        for (char c:s){
            temp_str=temp_str+c;
        }
    } 

};
