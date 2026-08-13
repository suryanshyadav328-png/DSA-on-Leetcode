class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0;
        unordered_map<int, int> freq;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++){

            freq[nums[right]]++;

            while(freq[nums[right]] > k){  // until frequency of tht element <= k
                
                freq[nums[left]]--;        // we'll remove frequencies from the left
               left++;
                

            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
