class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==1) ones++;
        }
        nums.insert(nums.end(),nums.begin(),nums.end());
        int ans=n;
        int i=0,j=0,one=0;
        while(j<2*n) {
            if(nums[j]==1) one++;
            if(j-i+1 == ones) {
                ans=min(ans,ones-one);
                one -= (nums[i]==1);
                i++;
            }
            j++;
        }
        return (ans==n ? 0:ans);
    }
};