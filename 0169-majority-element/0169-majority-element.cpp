class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        
        int count = 0;
        int ans;
        for( auto x : mp){
            if(x.second > count){
                ans = x.first;
                count = x.second;
            }
        }
        return ans;
        
    }
};