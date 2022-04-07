class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
      
      for (int i = 0; i < stones.size(); i++)
        pq.push(stones[i]);
      
      while (pq.size() > 1)
      {
        int a1 = pq.top();
        pq.pop();
        int a2 = pq.top();
        pq.pop();
        
        if (a1 > a2)
          pq.push(a1-a2);
      }
      return (pq.size()) ? pq.top() : 0;
    }
};