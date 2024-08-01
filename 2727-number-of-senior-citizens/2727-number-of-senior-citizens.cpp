class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto detail : details)
        {
            if((detail[11] > '6')||(detail[11] == '6' && detail[12] != '0')) count++;
        }
        return count;
    }
};