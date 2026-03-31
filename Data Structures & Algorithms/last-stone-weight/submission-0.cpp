class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;
        int res = 0;
        
        for(int st : stones) {
            maxHeap.push(st);
        }

        while(maxHeap.size() > 1) {
            int wt1 = maxHeap.top();
            maxHeap.pop();
            int wt2 = maxHeap.top();
            maxHeap.pop();

            if(wt1 > wt2) {
                int wt3 = wt1 - wt2;
                maxHeap.push(wt3);
            }
            else if(wt2 > wt1) {
                int wt3 = wt2 - wt1;
                maxHeap.push(wt3);
            }
        }

        if(maxHeap.size() == 1) {
            res = maxHeap.top();
        }
        else
        {
            res = 0;
        }

        return res;
    }
};
