class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry=1, sum=0;
        vector<int> res;

        for(int i=digits.size()-1; i>=0; i--) {
            sum = carry + digits[i];
            carry = sum/10;
            res.insert(res.begin(), sum%10);
        }

        if(carry) {
            res.insert(res.begin(), carry);
        }

        return res;

    }
};
