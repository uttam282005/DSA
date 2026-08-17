// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit
//
// Example 1:Input: nums = [8, 2, 4, 7], limit = 4
// ai > 0
// Output: 2
//
// Explanation:
// All subarrays of size 1 satisfy the condition.
// For size 2:
// [8, 2] has an absolute diff of $|8 - 2| = 6 > 4$.
// [2, 4] has an absolute diff of $|2 - 4| = 2 \le 4$.
// [4, 7] has an absolute diff of $|4 - 7| = 3 \le 4$.
// For size 3:
// [2, 4, 7] has a max element of 7 and min element of 2. The absolute diff is $|7 - 2| = 5 > 4$.
// Therefore, the maximum length is 2.
//
//
//
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int longestSubArray(vector<int> &nums, int limit) {
    map<int, int> mp;
    int left = 0;
    int maxLen = -1;
    for(int right = 0; right < nums.size(); right++) {
        mp[nums[right]]++;
        int mini = mp.begin()->first;
        int maxi = mp.rbegin()->first;

        if (abs(maxi - mini) <= limit) maxLen = max(maxLen, right - left + 1);
        else {
            mp[nums[left]]--;
            if (mp[nums[left]] == 0) {
                mp.erase(nums[left]);
            }
            left++;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, 10, 2, 9, 3, 8};
    int limit = 7;

   cout << longestSubArray(nums, limit);
}


// users table
// user_id | username | pfp_url (s3llink)

// chats table
// chat_id | type | user_id[]
//
// message table
//
// message_id | chat_id | user_id | type | link
