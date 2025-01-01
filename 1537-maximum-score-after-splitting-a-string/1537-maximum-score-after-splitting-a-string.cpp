class Solution {
public:
    int maxScore(string s) {
        int oneCount = 0;
        int maxScore = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '1') 
                oneCount++;
        }
        int zeroCount = 0;
        for(int i = 0; i < n-1; ++i)
        {
            if(s[i] == '1') oneCount--;
            else zeroCount++;
            maxScore = max(maxScore, zeroCount + oneCount);
        }
        return maxScore;
    }
};