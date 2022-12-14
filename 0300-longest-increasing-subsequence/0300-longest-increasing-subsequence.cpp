class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); //prev is stored at +1 index ,curr>=n ->0
        
        for(int curr=n-1;curr>=0;--curr){
            for(int prev=curr-1;prev>=-1;--prev){
                if(prev==-1 || nums[curr]>nums[prev])
                    dp[curr][prev+1]=max(1+dp[curr+1][curr+1],dp[curr+1][prev+1]);
                else dp[curr][prev+1]=dp[curr+1][prev+1];
            }
        }
        return dp[0][-1+1];   // prev stored at +1 index
    
    }
};