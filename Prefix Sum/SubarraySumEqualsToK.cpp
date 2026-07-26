/*Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
 
Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 10
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    int res = 0;

    unordered_map<int, int> freq;

    freq[0] = 1;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        int required = sum - k;

        if (freq.find(required) != freq.end()) {
            res += freq[required];
        }

        freq[sum]++;
    }

    return res;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    cout << "Number of subarrays = " << subarraySum(nums, k) << endl;

    return 0;
}