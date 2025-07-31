#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:

int counter(vector<int> &nums, int mid, int low, int high) {
    int cnt = 0;
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while(left <= mid && right <= high) {
        if (nums[left] < nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(nums[left++]);
    }

    while(right <= high) {
        temp.push_back(nums[right++]);
    }


    left = low;
    right = mid + 1;

    while(left <= mid && right <= high) {
        if (nums[left] > 2LL * nums[right]) cnt += mid - left + 1, right++;
        else left++;
    }
    
    for(int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }

    return cnt;
}

int countReversePairs(vector<int> &nums, int left, int right) {
    int cnt = 0;
    if (left >= right) return cnt;
    int mid = (left + right) / 2;
    cnt += countReversePairs(nums, left, mid);
    cnt += countReversePairs(nums, mid + 1, right);
    cnt += counter(nums, mid, left ,right);
    return cnt;
}

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = countReversePairs(nums, 0, n - 1);
        return ans;
    }
};

int main() {
    Solution S;
  vector<int> nums = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
cout <<  S.reversePairs(nums );
    return 0;
}
