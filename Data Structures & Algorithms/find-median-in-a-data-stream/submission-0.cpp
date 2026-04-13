class MedianFinder {
public:
    MedianFinder() {
        //na
        
    }
    
    void addNum(int num) {
        ++size;
        if(size % 2 == 1)
        {
            if(maxHeap.empty() && minHeap.empty())
            {
                maxHeap.push(num);
                minHeap.push(num);
            }
            else
            {
                //if num causing everything to shift right
                if(num <= maxHeap.top())
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.push(num);
                }
                else if(num >= minHeap.top())
                {
                    //shifting left
                    maxHeap.push(minHeap.top());
                    minHeap.push(num);

                }
                else if(num > maxHeap.top() && num < minHeap.top())
                {
                    minHeap.push(num);
                    maxHeap.push(num);
                }
                
            }

        }
        else
        {
            if(num <= maxHeap.top())
            {
                maxHeap.pop();
                maxHeap.push(num);
            }
            else if(num >= minHeap.top())
            {
                minHeap.pop();
                minHeap.push(num);
            }

        }

        
    }
    
    double findMedian() {
        if(size % 2 == 1)
        {
            return minHeap.top();
        }
        else
        {
            int one = minHeap.top();
            int two = maxHeap.top();
            double result = (one + two) / 2.0;
            return result;
        }
        
    }
private:
    int size = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
