class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char, int> mp;

        for(auto x : text){
            mp[x]++;
        }

        string s = "balloon"; 
        unordered_map<char , int> freq;
        for(auto m : s){
            freq[m]++;
        }
        int ans  = INT_MAX;
        for(auto p : freq){
            ans = min(ans, mp[p.first] / p.second);
        }
        return ans;
    }
};