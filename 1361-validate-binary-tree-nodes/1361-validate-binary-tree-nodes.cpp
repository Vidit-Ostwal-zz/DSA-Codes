class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
      
      vector<bool> Visited(n,true);
      vector<int> parent(n,0);
      
      for (int i = 0; i < n; i++)
      {
        if (leftChild[i] != -1)
          parent[leftChild[i]]++;
        
        if (rightChild[i] != -1)
          parent[rightChild[i]]++;
      }
      
      int parent_count = 0;
      int index = -1;
      int parent_index = -1;
      
      for (int i = 0; i < n; i++)
      {
        if (parent[i] == 0)
        {
          parent_count++;
          parent_index = i;
        }
        else if (parent[i] == 2)
          return false;
        else
          continue;
      }
      
      if (parent_count != 1)
        return false;
      
      queue<int> pq;
      
      Visited[parent_index] = false;
      pq.push(parent_index);
      
      // cout << parent_index << endl;
      while (!pq.empty())
      {
        int root = pq.front();
        pq.pop();
        
        int left_child = leftChild[root];
        int right_child = rightChild[root];
        
        if (left_child != -1)
        {
          if (Visited[left_child])
          {
            Visited[left_child] = false;
            pq.push(left_child);
          }
          else
            return false;
        }
        
        if (right_child != -1)
        {
          if (Visited[right_child])
          {
            Visited[right_child] = false;
            pq.push(right_child);
          }
          else
            return false;
        }
      }
      
      
      for (int i = 0; i < n; i++)
        if (Visited[i])
          return false;
      return true;
    }
};