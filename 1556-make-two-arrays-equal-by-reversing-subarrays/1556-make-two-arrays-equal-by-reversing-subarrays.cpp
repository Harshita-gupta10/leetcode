class Solution {
public:
        bool areEqual(unordered_map<int, int>& freqArr, unordered_map<int, int>& freqTarget) {
        if (freqArr.size() != freqTarget.size()) {
            return false;
        }
        
        for (const auto& pair : freqArr) {
            int key = pair.first;
            int value = pair.second;
            
            if (freqTarget.find(key) == freqTarget.end() || freqTarget.at(key) != value) {
                return false;
            }
        }
        return true;
    }
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map <int, int> freqArr;
        unordered_map <int, int> freqTarget;

        for(auto a : arr)
        {
            freqArr[a]++;
        }
        for(auto t : target)
        {
            freqTarget[t]++;
        }
        if(areEqual(freqArr, freqTarget)) return true;
        return false;
    }
};