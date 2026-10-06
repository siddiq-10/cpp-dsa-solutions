#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    int sop(string s){
        stack<int> st;
        st.push(0);
        for(char c:s){
            if(c=='('){
                st.push(0);
            }
            else{
                int cs=st.top();
                st.pop();
                int calculated=(cs==0) ? 1:2*cs;
                st.top()+=calculated;
            }

        }
        return st.top();
    }
};
