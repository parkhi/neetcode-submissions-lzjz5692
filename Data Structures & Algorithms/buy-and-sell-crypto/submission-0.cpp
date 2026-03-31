class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ind1 = 0, ind2 = 1;
        int max = 0, temp = 0;
        int size = prices.size();

        if(size <= 1)
            return 0;

        while ((ind2 >= ind1) && (ind2 < size))
        {
            if( prices[ind2] < prices[ind1])
            {
                ind1 = ind2;
            }
            else
            {
                temp = prices[ind2] - prices[ind1];
                if(temp > max)
                    max = temp;
            }

            ind2++;            
        }


        return max;
    }
};
