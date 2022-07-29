// 347. Top K Frequent Elements

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> pq;
        int i=0;
        while(i<nums.size()){
            freq[nums[i]]++;
            i++;
        }
        vector<int> res;
        for(auto i=freq.begin(); i!=freq.end(); i++){
            pair<int,int> ans;
            // ans.first=value
            ans.first=i->second;
            // ans.second=key
            ans.second=i->first;
            pq.push(ans);
            if(pq.size() > (int)freq.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};