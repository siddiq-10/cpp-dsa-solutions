// Minimum Operations to Sort a Subarray
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Case 1: Is the string already sorted?
        bool sorted = true;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted) return 0;

        // Case 2: Unsorted string of length 2
        if (n == 2) return -1;

        // Find minimum and maximum characters
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Case 3: One operation is enough
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Case 4: Check the middle characters
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        // Case 5: Worst case
        return 3;
    }
};