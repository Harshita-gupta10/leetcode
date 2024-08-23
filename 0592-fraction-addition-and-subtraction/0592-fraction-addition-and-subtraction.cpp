class Solution {
public:
    string fractionAddition(string expression) {
       int num=0;
       int den=1;
       
       int i=0;
       int n=expression.length();
       while(i<n) {
        int currNum=0;
        int currDen=0;

        bool isNeg=(expression[i]=='-');

        if(expression[i]=='+' || expression[i]=='-') i++;

        //build the numerator
        while(i<n && isdigit(expression[i])) {
            int val=expression[i]-'0';
            currNum=(currNum*10)+val;
            i++;
        }

        i++; // divisor character skip
        if(isNeg) currNum*=-1;

        while(i<n && isdigit(expression[i])) {
            int val=expression[i]-'0';
            currDen=(currDen*10) + val;
            i++;
        }

        num= num*currDen + den*currNum;
        den= currDen*den;

       }

       int GCD = abs(__gcd(num,den));
       num /= GCD;
       den /= GCD;

       return to_string(num) + "/" + to_string(den);
    }
};