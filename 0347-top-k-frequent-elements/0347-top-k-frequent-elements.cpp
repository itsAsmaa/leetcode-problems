class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> counts;
        //count freq of each element using hash table
        for (int num : nums){
            counts[num]++;
        }

        // create buckets where the index represent the freq
        // the max possible freq is the total num of elements 
        vector<vector<int>> buckets(nums.size()+1);
        for (const auto& [num , freq]: counts ){
          buckets[freq].push_back(num);  
            
        }

        //iterate backward from highest freq bucket to collect 
        vector<int> result;
        for (int i = buckets.size() - 1; i > 0; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};