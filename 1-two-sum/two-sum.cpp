class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //anshul
        unordered_map<int, int> map; // Map to store the number and its index
        for(int i = 0; i < nums.size(); i++) 
        {
            int complement = target - nums[i]; // Calculate the required complement
            if(map.find(complement) != map.end()) 
            {
                // If complement is found, return its index and the current index
                return {map[complement], i};
            }
            // Store the current number with its index in the map
            map[nums[i]] = i;
        }
        return {};
    }
};