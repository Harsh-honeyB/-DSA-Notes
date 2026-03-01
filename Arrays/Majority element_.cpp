// Brute force Approach //
// TC : O(N^2)  SC : O(1) //
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            
            for(int j = 0; j < n; j++)
            {
                if(nums[i] == nums[j])
                {
                    count++;
                }
            }
            
            if(count > n/2)
            {
                return nums[i];
            }
        }
        
        return -1;
    }
};


// Better Approach //
// TC : O(N)  SC: O(N)
// Using Hashmap :- //
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n =  nums.size();
        map<int,int>mp;
        for(int i = 0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        for(auto it : mp)
        {
            if(mp[it.first] > n/2) return it.first;
        }
        return 0;
    }
};


// Optimal approach //
// TC : O(N)  SC : O(1)
// Using Boyer-Moore Voting Algorithm :- //
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        int cand = nums[0];
        int id = 0;
        for(int i = 0; i<n; i++)
        {
            if(cand == nums[i])
            {
                id++;
            }
            else if(id == 0)
            {
                cand = nums[i];
            }
            else if(cand!=nums[i])
            {
                id--;
            }
            
        }
        return cand;
        
    }
};
