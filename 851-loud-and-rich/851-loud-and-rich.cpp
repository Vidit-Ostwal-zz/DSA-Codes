class Solution {
  
  unordered_map<int,vector<int>> mapofedges;
  vector<bool> canvisit;
  vector<int> answer;
  
  
  //Reverses all the edges
  void make_map (vector<vector<int>> &B)
  {
    for (int i = 0; i < B.size(); i++)
      mapofedges[B[i][1]].push_back(B[i][0]);
  }

  
  void runDFS (int person, vector<int>&quiet)
  {
    canvisit[person] = false;
    
    for (int i = 0; i < mapofedges[person].size(); i++)
    {
      int next_person = mapofedges[person][i];
      
      if (canvisit[next_person])
        runDFS(next_person,quiet);
      
      int temp_person = answer[person];
      next_person = answer[next_person];
      if (quiet[next_person] < quiet[temp_person])
      {
        answer[person] = next_person;
      }
    }
    return;
  }
  
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
      
      // Why Topological Sorting Won't work
      // Becasue it can not gurantee that order, if 3rd person is richer than 1st and 2nd, with this infromation we can't comment on the 
      // who is richer between 1st and 2nd 
      
      
      // Now to find answer, for 1st person, we first need to find answer of all the people who is richer than 1st person 
      // with the given direction of edges if we reverse the direction of all the edsges and then, if we try DFS, before calculating answer for 
      // 1st person, we would have calculate answer, for all the people who are richer than him, and for finding answer, of 1st person, we would only 
      // consider it's immediate child answer and immediate child
      
      int N = quiet.size();
      canvisit = vector<bool> (N,true);
      answer = vector<int> (N,0);
      
      for (int i = 0; i < N; i++)
        answer[i] = i;
      
      make_map(richer);
      
      for (int i = 0; i < N; i++)
        if (canvisit[i])
          runDFS(i,quiet);
      
      return answer;
    }
};