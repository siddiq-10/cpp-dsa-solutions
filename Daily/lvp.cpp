// Longest Valid Parenthesis
#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
    int lvp(string s){
        int result=0;
        int open_count=0;
        int close_count=0;
        if (s.size()==0 || s.size()==1){
            return result; 
        }
        for (int i=0; i<s.size(); i++){
            if (s[i]=='('){
                open_count++;
            }
            if(s[i]==')'){
                close_count++;
            }
        }
        if (open_count>close_count){
            result=(open_count-close_count)*2;
        }
        if (close_count>open_count){
            result=(close_count-open_count)*2;
        }
        if (open_count==close_count){
            result=open_count*2;
        }
        return result;

    }
};

int main(){
    Solution test1;
    string s="()";
    int result=test1.lvp(s);
    cout<<"The final result: "<<result<<endl;
    return 0;
}