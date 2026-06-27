class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=0; i<2*n; i++){
            int curridx = i%n;
            int currval = nums[curridx];

            while(!st.empty() && nums[st.top()] < currval){
                ans[st.top()] = currval;
                st.pop();
            }

            if(i < n){
                st.push(curridx);
            }
        }
        return ans;

        
    }
};