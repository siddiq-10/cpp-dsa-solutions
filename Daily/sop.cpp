// Solving Score of Parentheses
#include<iostream>
#include<stack>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
 class Solution {
public:
    int sop(string s){
        stack<char> open_brac;
        int sop=0;
        int streak=0;
        int maxstreak=0;
        vector<int> streaks;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='('){
                open_brac.push(s[i]);
                streak=0;
                maxstreak++;
            }
            else{
                streaks.push_back(maxstreak);
                maxstreak=0;
                if (open_brac.empty()){
                    return sop;
                }
                else{
                    if (maxstreak>1){
                        sop=sop+pow(2, maxstreak);
                        maxstreak=0;
                    }
                    open_brac.pop();
                    streak++;
                    sop=pow(2,streak);
                }
            }
        }
        return sop;       
    }
 };
 
 int main(){
    Solution test1;
    string s1="(()(()))";
    int result=test1.sop(s1);
    cout<<"Result: "<<result<<endl;
    return 0;
 }