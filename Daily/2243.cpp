// 2243 ~ Calculate Digit Sum of a String
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
    string digsum(string s, int k){
        while(s.length()>k){
            string ss="";
            for (int i=0; i<s.length(); i+=3){
                string temp=s.substr(i, 3);
                int num=0;
                for (char c: temp){
                    num+=c-'0';
                }
                ss+=to_string(num);
            }
            s=ss;
        }
        return s;
    }
};

int main(){
    string s="111222233";
    string s2="";
    for (int i=0; i<s.length(); i+=3){
        string temp=s.substr(i, 3);
        int num=0;
        for (char c:temp){
            num+=c-'0';
        }     
        s2+=num+'0';
        cout<<"Temp Str: "<<temp<<" Sum: "<<num<<" Sum as String: "<<to_string(num)<<endl;
    }
    cout<<"This is new string: "<<s2<<endl;
    cout<<"Let's go with the program:: "<<endl;
    Solution test;
    string s1="11111222223";
    string s_result=test.digsum(s1, 3);
    cout<<"Result: "<<s_result<<endl;
    return 0;
}