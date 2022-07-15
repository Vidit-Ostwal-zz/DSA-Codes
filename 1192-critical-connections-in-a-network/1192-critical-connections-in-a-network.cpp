class Solution {
  
  unordered_map<int,vector<int>> mapofedges;
  vector<vector<int>> answer;
  vector<bool> canVisit;
  vector<int> distime;
  vector<int> lowtime;
  
  int time = 1;
  
  void make_map (vector<vector<int>> &B)
  {
    for (int i = 0; i < B.size(); i++)
    {
        mapofedges[B[i][0]].push_back(B[i][1]);
        mapofedges[B[i][1]].push_back(B[i][0]);
    }
  }
  
  void dfstraverse(int index,int parent)
  {
    // cout << index << "   " << parent << endl;
    
    canVisit[index] = false;
    distime[index] = time;
    lowtime[index] = time++;
    
    for (int i = 0; i < mapofedges[index].size(); i++)
    {
      int curr_node = mapofedges[index][i];
      
      if (curr_node == parent)
        continue;
      else if (!canVisit[curr_node])
      {
        // this particular edge can never be a bridge as the other point is already visited
        lowtime[index] = min(lowtime[index],lowtime[curr_node]);
      }
      else
      {
        dfstraverse(curr_node,index);
        lowtime[index] = min(lowtime[index],lowtime[curr_node]);
        
        // equality will hold in cut vertex
        // equality in here means that tere is a diff path through which it gets connected
        // in cut vertex equality will also be a danger because we are going to remove all the edges, here only one 
        if (lowtime[curr_node] > distime[index])
          answer.push_back({curr_node,index});
      }
    }
    
    return;
  }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
      make_map(connections);
      canVisit = vector<bool> (n,true);
      distime = vector<int> (n,0);
      lowtime = vector<int> (n,0);
      
      
      for (int i = 0; i < n; i++)
      {
        if (canVisit[i])
          dfstraverse(i,-1);
      }
      return answer;
    }
};