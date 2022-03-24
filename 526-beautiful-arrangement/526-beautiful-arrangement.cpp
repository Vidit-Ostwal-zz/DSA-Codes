class Solution {
  int count = 0;
  /*Visited array basically reperesent the elemtents which are taken*/
  void get_combo(vector<bool> visited,int n, int index)
  {
    if (index > n)
    {
      count++;
      return ;
    }
    
    for (int i = 1; i < visited.size(); i++)
    {
      if (visited[i])
      {
        if (i % index  == 0 || index % i == 0)
        {
          visited[i] = false;
          get_combo(visited,n,index+1);
          visited[i] = true;
        }
      }
    }
    return;
  }
public:
    int countArrangement(int n) {
        
      vector<bool> visited(n+1,true);
      get_combo(visited,n,1);
      return count;
    }
};