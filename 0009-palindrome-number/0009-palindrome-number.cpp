class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> digits;
        while(x != 0)
        {
            int digit = x % 10;
            digits.push_back(digit);
            x = x / 10;
        }
        int s = 0;
        int e = digits.size() - 1;
        while(s < e)
        {
            if(digits[s] != digits[e])
                return false;
            s++;
            e--;
        }
        return true;
    }
};