// Removing outermost parentheses
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution{
public:
    string rop(string s){
        stack<int> index;
        string result="";
        for (int i=0; i<s.size(); i++){
            if (s[i]=='('){
                index.push(i);
                if (index.size()==1){
                    continue;
                }
                else{
                    result+=s[i];
                }
            }
            else{
                if (index.size()==1){
                    index.pop();
                    continue;
                }
                else{
                    result+=s[i];
                    index.pop();
                }
            }
        }
        return result;
    }
};

int main(){
    Solution test;
    string s1="(()())(())(()(()))";
    string result=test.rop(s1);
    cout<<"Result: "<<result<<endl;
    return 0;
}