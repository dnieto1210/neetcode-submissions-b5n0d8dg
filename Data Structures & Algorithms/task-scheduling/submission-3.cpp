class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int>letters(26,0);
        for(char c : tasks)
        {
            letters[c-'A']++;
        }

        priority_queue<int> maxHeap;


        for(int i : letters)
        {
            if(i > 0)
            {
                maxHeap.push(i);
            }
        }
        using Node = pair<int,int>;
        priority_queue<Node, vector<Node>, greater<Node>> coolDown;
        int time = 0;

        while(!maxHeap.empty() || !coolDown.empty())
        {
            while(!coolDown.empty() && coolDown.top().first <= time)
            {
                maxHeap.push(coolDown.top().second);
                coolDown.pop();
            }

            if(maxHeap.empty())
            {
                time = coolDown.top().first;
                continue;
            }

            int freq = maxHeap.top();
            maxHeap.pop();
            --freq;
            if(freq > 0)
            {
                coolDown.push({time+n+1, freq});
            }
            ++time;
        }
        
        return time;
    }
};
