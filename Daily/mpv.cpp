// Minimum add to make parentheses valid
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution{
public:
    int mpv(string s){
        stack<char> st;
        int count=0;
        for(char c:s){
            if (c=='('){
                st.push(c);
                count++;
            }
            else{
                if (st.empty()){
                    count++;
                }
                else{
                    st.pop();
                    count--;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution test;
    string s1=")())((()";                 //4
    int result=test.mpv(s1);
    cout<<"Result: "<<result<<endl;
    return 0;
}