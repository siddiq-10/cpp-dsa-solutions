// Find Centre of Star Graph ~ O(1) Optimised
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
public:
    int fcsg(vector<vector<int>> edges){
        if (edges[0][0]==edges[1][0] ||
            edges[0][0]==edges[1][1]){
                return edges[0][0];
            }
        return edges[0][1];
    }
};

int main(){
    Solution test;
    vector<vector<int>> edges={{1,2},{5,1},{1,3},{1,4}};
    int result=test.fcsg(edges);
    cout<<"Result: "<<result<<endl;
    return 0;
}