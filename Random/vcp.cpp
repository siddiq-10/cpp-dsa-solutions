// Solving for Valid Curly Parentheses
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution{
public:
    bool vcp(string s){
        stack<char> st;
        if (s.size()%2!=0){
            return false;
        }
        for (int i=0; i<s.size(); i++){
            if (s[i]=='('){
                st.push(s[i]);
            }
            else{
                if (st.empty()){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }

    }
};
int main(){
    Solution test1;
    string test_s1=")())((()";
    bool result1=test1.vcp(test_s1);
    cout<<"Result: "<<result1<<endl;
    return 0;
}