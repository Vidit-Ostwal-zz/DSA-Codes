class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis (rooms.size(),true);
      vis[0] = false;
      
      queue<int> q;
      for (int i = 0; i < rooms[0].size();i++)
        q.push(rooms[0][i]);
      
      while (!q.empty())
      {
        int index = q.front();
        q.pop();
        
        if (vis[index])
        {
          vis[index] = false;
          for (int i = 0; i < rooms[index].size(); i++)
            q.push(rooms[index][i]);
        }
      }
      for (int j = 0; j < vis.size(); j++)
        if (vis[j])
          return false;
      
      return true;
    }
};