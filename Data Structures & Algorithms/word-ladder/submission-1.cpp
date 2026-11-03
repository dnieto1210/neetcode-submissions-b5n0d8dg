class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string, vector<string>> adjList;
        unordered_map<string, int> dist;
        unordered_set<string> mySet;

        bool valid = false;
        for(string w : wordList) {

            mySet.insert(w);
            if(w == endWord) {
                valid = true;
            }
        }

        if(valid == false) {
            return 0;
        }
        
        dist[beginWord] = 0;
        queue<string> myQ;
        myQ.push(beginWord);

        while(!myQ.empty()) {
            string curr = myQ.front();
            myQ.pop();

            if(curr == endWord) {
                return dist[endWord] + 1;
            }

            string copy = curr;
            for(int i = 0; i < curr.size(); ++i) {
                char c = curr[i];
                for(int j = 0; j < 26; ++j) {
                    char change = 'a' + j;
                    if(change != c) {
                        copy[i] = change;
                    }
                    else
                    {
                        continue;
                    }
                    
                    if(mySet.find(copy) != mySet.end()) {
                        adjList[curr].push_back(copy);
                        //mySet.erase(curr);
                    }
                }
                copy[i] = c;
            }

            for(int i = 0; i < adjList[curr].size(); ++i) {
                string w = adjList[curr][i];
                if(dist.find(w) != dist.end()) {
                    continue;
                }

                dist[w] = dist[curr] + 1;
                myQ.push(w);
            }

        }

        return 0;
    }
};
