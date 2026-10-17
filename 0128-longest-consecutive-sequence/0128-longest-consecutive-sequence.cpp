#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        //step 1 :  sort (arrange cards in order  1,2,3,200,900....)
        sort(nums.begin() , nums.end());

        int longest =1 ;
        int current_len =1;
        // step 2 : linear scan to find consecutive streaks
        for (size_t i = 1; i<nums.size(); ++i){
            if (nums[i] == nums[i - 1]) {
                continue;}//ignore duplicates

            if (nums[i] == nums[i - 1] + 1) {//If this card is exactly 1 higher than the last card..
                current_len++;     
            }else{
                // Sequence broke, reset the streak
                longest =max(longest, current_len);
                current_len = 1;
            }
        }

        // final check for the last sequence
        return max(longest, current_len);
    }
};