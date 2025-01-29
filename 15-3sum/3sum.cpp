class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        // vector<vector<int>> ans;
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(i > 0 && nums[i] == nums[i-1]) continue;
        //     for(int j = i+1; j < nums.size(); j++)
        //     {
        //         if(j > i+1 && nums[j] == nums[j-1]) continue;
        //         for(int k = j+1; k < nums.size(); k++)
        //         {
        //             if(k > j+1 && nums[k] == nums[k-1]) continue;
        //             if((i != j && i != k && j != k) && (nums[i]+nums[j]+nums[k] == 0))
        //             {
        //                 vector<int> triplet = {nums[i], nums[j], nums[k]};
        //                 ans.push_back(triplet);
        //             }
        //         }
        //     }
        // }    

        // return ans;

        set<vector<int>> uniqueTriplets;
        int n =nums.size();

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++)
        {
            int left = i+1, right = n-1;
            int target = -nums[i];
            
            while(left < right)
            {
                int sum = nums[right]+nums[left];
                if(sum == target)
                {
                    vector<int> ele = {nums[i], nums[left], nums[right]};
                    uniqueTriplets.insert(ele);
                    left++;
                    right--;
                }

                else if(sum < target)
                    left++;
                else
                    right--;
            }
        }

        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};