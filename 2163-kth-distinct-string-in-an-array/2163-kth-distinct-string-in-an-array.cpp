class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        for(auto i : arr) freq[i]++;

        int count = 0;
        
        for(auto& s : arr)
        {
            if(freq[s] == 1 && --k == 0)
                return s;
        }
        return "";
    }
};