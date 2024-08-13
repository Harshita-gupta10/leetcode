class Solution {
public:
    // TC : O(2^N), SC : O(N)
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& curr, int idx)
    {
        if(target < 0) return;
        int n = candidates.size();
        if(target == 0) 
        {
            result.push_back(curr);
            return;
        }
        for(int i = idx; i < n; i++)
        {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            curr.push_back(candidates[i]); //Do
            solve(candidates, target-candidates[i], result, curr, i+1); //Explore
            curr.pop_back(); //Undo
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, result, curr, 0);

        return result;
    }
};