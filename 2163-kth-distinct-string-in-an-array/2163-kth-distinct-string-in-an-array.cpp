class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        for(auto i : arr) freq[i]++;

        int count = 0;
        string ans = "";
        for(int i = 0; i < arr.size(); i++)
        {
            if(freq[arr[i]] > 1) continue;
            count++;
            if(count == k) ans = arr[i];
        }
        return ans;
    }
};