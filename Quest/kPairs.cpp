// Find K Pairs with smallest sum
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<numeric>
using namespace std;

class Solution{
struct compare{
    bool operator()(const vector<int> & a,
                    const vector<int>& b){
        return accumulate(a.begin(), a.end(), 0) >
                accumulate(b.begin(), b.end(), 0);
    }
};
public:
    vector<vector<int>> kp(vector<int> nums1, vector<int> nums2, int k){
        unordered_map<int, vector<int>> sum_list;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<vector<int>, vector<vector<int>>, compare> minHeap2;
        vector<vector<int>> result;
        for (int n:nums1){
            for (int m:nums2){
                sum_list[n+m]={n,m};
                minHeap.push(n+m);
                minHeap2.push({n,m});
            }
        }
        for (int i=0; i<k; i++){
            result.push_back(minHeap2.top());
            minHeap2.pop();
        }
        return result;
        
    }
};
int main(){
    Solution test;
    vector<int> nums1={1,2,4,5,6};
    vector<int> nums2={3,5,7,9};
    int k=20;
    vector<vector<int>> result=test.kp(nums1, nums2, k);                //[[1,3],[2,3],[1,5],[2,5],[4,3],[1,7],[5,3],[2,7],[4,5],
    for (int i=0; i<k; i++){                                            //[6,3],[1,9],[5,5],[2,9],[4,7],[6,5],[5,7],[4,9],[6,7],[5,9],[6,9]]
        cout<<"Result: "<<result[i][0]<<result[i][1]<<endl;
    }
    cout<<"Bug Check: "<<result[4][0]<<endl;
    return 0;
}
