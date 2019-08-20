#include "common.h"

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        deque<int> index;
        vector<int> maxWindows;
        
        int length = num.size();
        if(length < int(size) || size < 1)
            return maxWindows;
        for(unsigned int i = 0; i < size; i++){
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        for(unsigned int i = size; i < length; i++){
            maxWindows.push_back(num[index.front()]);
            while(!index.empty() && num[index.back()] <= num[i])
                index.pop_back();
            if(!index.empty() && index.front() <= int(i - size))
                index.pop_front();
            index.push_back(i);
        }
        maxWindows.push_back(num[index.front()]);
        return maxWindows;
    }
};
