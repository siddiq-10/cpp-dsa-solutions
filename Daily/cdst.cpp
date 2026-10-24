// Count Days Spent Together
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        
        int days[] = {0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        auto toDays = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            int total = day;
            for (int i = 1; i < month; i++) {
                total += days[i];
            }
            return total;
        };

        int start = max(toDays(arriveAlice), toDays(arriveBob));
        int end = min(toDays(leaveAlice), toDays(leaveBob));

        return max(0, end - start + 1);
    }
};


int main(){
    Solution test;
    string aa="08-15";
    string la="08-19";
    string ab="08-16";
    string lb="08-19";
    int result=test.countDaysTogether(aa, la, ab, lb);
    cout<<"Result: "<<result<<endl;
    return 0;
}