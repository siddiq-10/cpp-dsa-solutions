// 3963 ~ Create Grid With Exactly One Path
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution{
public:
        vector<string> OnePath(int m, int n){
            vector<string> result;
            if (m==1){
                string s="";
                for (int i=0; i<n; i++){
                    s+='.';
                }
                result.push_back(s);
                return result;
            }
            for(int i=0; i<m; i++){
                string s="";
                for (int j=0; j<n; j++){
                    if (i==0 || j==n-1){
                        s+='.';
                    }
                    else{
                        s+='#';
                    }
                }
                result.push_back(s);
            }
            return result;
        }
};

int main(){
    Solution test;
    int m=3;
    int n=3;
    vector<string> result=test.OnePath(m, n);
    for (int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    return 0;
}