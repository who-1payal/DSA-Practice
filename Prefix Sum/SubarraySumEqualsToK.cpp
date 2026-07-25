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