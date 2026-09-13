class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Unnecessary rotations se bachne ke liye

        // Step 1: Poore array ko reverse karo
        reverse(nums.begin(), nums.end());
        
        // Step 2: First k elements ko reverse karo
        reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Remaining elements ko reverse karo
        reverse(nums.begin() + k, nums.end());
    }
};