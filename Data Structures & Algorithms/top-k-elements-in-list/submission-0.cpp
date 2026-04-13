class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Use a min-heap to keep track of the top k elements
        // The heap stores pairs of (frequency, number)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (const auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Extract the elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;

        

        
    }
};
