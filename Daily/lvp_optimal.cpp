#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution{
public: 
    int lvp(string s){
        stack<int> st;
        st.push(-1);
        int lvp=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if (st.empty()){
                    st.push(i);
                }
                else{
                    lvp=max(lvp, i-st.top());
                }
            }
        }
        return lvp;
    }
};

int main(){
    Solution test1;
    string s1=")(()";
    string s2=")())((()";
    int result=test1.lvp(s2);
    cout<<"Result: "<<result<<endl;
    return 0;
}