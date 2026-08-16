class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it : stones){
            pq.push(it);
        }
        while(pq.size() > 1){
            int firstL = pq.top();
            pq.pop();
            int secondL = pq.top();
            pq.pop();
            if(secondL < firstL){
                pq.push(firstL-secondL);
            }
        }
        pq.push(0);
        return pq.top();
    }
};
