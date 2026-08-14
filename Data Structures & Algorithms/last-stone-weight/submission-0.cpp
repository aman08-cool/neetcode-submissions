class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        while (stones.size() > 1) {

            // Sort so the two heaviest stones are at the end
            sort(stones.begin(), stones.end());

            int largest = stones.back();
            stones.pop_back();

            int secondLargest = stones.back();
            stones.pop_back();

            // If they are different, put their difference back
            if (largest != secondLargest) {
                stones.push_back(largest - secondLargest);
            }
        }

        // Return the remaining stone, or 0 if none remains
        return stones.empty() ? 0 : stones[0];
    }
};