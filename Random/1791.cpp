// Find Centre of Star Graph ~ O(n)
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
public:
    int fcsg(vector<vector<int>> edges){
        unordered_map<int, int> connections;
        int result=0;
        for (vector<int> list : edges){
            connections[list[0]]++;
            connections[list[1]]++;
        }
        for (int i=1; i<connections.size()+1; i++){
            if (connections[i]==connections.size()-1){
                result=i;
            }
        }
        return result;
    }
};

int main(){
    Solution test;
    vector<vector<int>> edges={{1,2},{5,1},{1,3},{1,4}};
    int result=test.fcsg(edges);
    cout<<"Result: "<<result<<endl;
    return 0;
}