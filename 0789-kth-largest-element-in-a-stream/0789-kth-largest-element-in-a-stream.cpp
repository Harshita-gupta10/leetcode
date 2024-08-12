class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int& num : nums)
        {
            pq.push(num);

            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        int k = K;
        pq.push(val);
        if(pq.size() > k)
                pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */