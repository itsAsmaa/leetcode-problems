#include <vector>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate =0 ;
        int count =0;

        for(int num : nums){
           if(count==0){
             candidate = num;
             count = 1;
           }else if (num==candidate){
            count++;
           }else {
            count--;
           }
        }
        int actualCount = 0;
    for (int num : nums) {
        if (num == candidate) {
            actualCount++;
        }
    }

    if (actualCount > nums.size() / 2) {
        return candidate;
    }

    return -1; // return -1 if no majority element exists
}
    
};