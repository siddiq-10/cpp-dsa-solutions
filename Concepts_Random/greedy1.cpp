// Assign Cookies
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int ac(vector<int> g, vector<int> s){
        sort(g.begin(), g.end());
        sort(s.begin(), s.begin());
        int i=0;
        int j=0;
        while(i<g.size() && j<s.size()){
            if (s[j]>=g[i]){
                i++;
            }
            j++;
        }
        return i;
    };
};

int main(){
    Solution test;
    vector<int> g={10,9,8,7};
    vector<int> s={5,6,7,8};
    int result=test.ac(g, s);
    cout<<"Result: "<<result<<endl;
    return 0;
}