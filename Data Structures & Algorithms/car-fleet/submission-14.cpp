class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        using Node = std::pair<int,int>;
        vector<Node> coords(position.size());
        for(int i = 0; i < position.size(); ++i)
        {
            coords[i] = {position[i], speed[i]};
        }

        sort(coords.begin(), coords.end());
        stack<double> myStack;

        for(int i = position.size()-1; i >= 0; --i)
        {
            Node curr = coords[i];
            int pos = curr.first;
            int spe = curr.second;
            double x = static_cast<double>(target - pos) / static_cast<double>(spe);
            if(!myStack.empty() && x <= myStack.top())
            {
                continue;   
            }
            myStack.push(x);
        }

        return myStack.size();
        
    }
};
