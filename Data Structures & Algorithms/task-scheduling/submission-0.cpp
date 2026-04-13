class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {


        vector<int> freq(26, 0);
        for(int i = 0; i < tasks.size(); ++i)
        {
            char c = tasks[i];
            freq[c-'A']++;
        }

        priority_queue<int> maxHeap;
        for(int i : freq)
        {
            if(i > 0)
            {
                maxHeap.push(i);
            }
        }
        //priority_queue<int> maxHeap(freq.begin(), freq.end());


        using Node = pair<int,int>;
        queue<Node> q;
        int time = 0;

        while(!maxHeap.empty() || !q.empty())
        {
            if(maxHeap.empty())
            {
                time = q.front().second;
            }

            while(!q.empty() && q.front().second <= time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }

            if(!maxHeap.empty())
            {
                int curr = maxHeap.top();
                maxHeap.pop();
                --curr;
                if(curr > 0)
                {
                    q.push({curr, time+n+1});
                }
            }
            ++time;


        }

        return time;

        
    }
};
