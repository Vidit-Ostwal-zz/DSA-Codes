class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
      
      priority_queue<int,vector<int>,greater<int>> pq;
      
      int index_to_check = 1;
      
      while (index_to_check < heights.size())
      {
        if ((heights[index_to_check] - heights[index_to_check-1]) > 0)
        {
          if (ladders)
          {
            pq.push(heights[index_to_check] - heights[index_to_check-1]);
            ladders--;
          }
          else
            break;
        }
        
        index_to_check++;
      }
      
      // cout << index_to_check << endl;
      while (index_to_check < heights.size())
      {
        if ((heights[index_to_check] - heights[index_to_check-1]) > 0)
        {
          int req = heights[index_to_check] - heights[index_to_check-1];
          
          if (!pq.empty() && req > pq.top())
          {
            if (pq.top() <= bricks)
            {
              bricks -= pq.top();
              pq.pop();
              pq.push(req);
            }
            else
              break;
          }
          else
          {
            if (bricks >= req)
              bricks -= req;
            else
              break;
          }
        }
        
        index_to_check++;
      }
      
      return index_to_check-1;
    }
};