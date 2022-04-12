class LockingTree {
  vector<int> tree;
  unordered_map<int,vector<int>> u1;
  vector<int> locked;
  
  
  bool check_lower (int num)
  {
    queue<int> q;
    q.push(num);
    
    int count = 0;
    while (!q.empty())
    {
      int root = q.front();
      q.pop();
      
      // cout << root << endl;
      if (locked[root] != -1)
        count++;
      
      for (int j = 0; j < u1[root].size(); j++)
        q.push(u1[root][j]);
    }
    if (count >= 1)
      return true;
    return false;
  }
  
  bool check_upper (int num)
  {
    queue<int> q;
    q.push(num);
    
    int count = 0;
    while (!q.empty() && !count)
    {
      int root = q.front();
      q.pop();
      
      if (locked[root] != -1)
        count++;
      
      if (tree[root] != -1)
        q.push(tree[root]);
    }
    
    if (count)
      return false;
    return true;
  }
  
  void change_lower (int num)
  {
    queue<int> q;
    q.push(num);
    
    while (!q.empty())
    {
      int root = q.front();
      q.pop();
      
     locked[root] = -1;
      
      for (int j = 0; j < u1[root].size(); j++)
        q.push(u1[root][j]);
    }
  }
public:
    LockingTree(vector<int>& parent) {
        tree = vector<int>(parent.begin(),parent.end());
      locked = vector<int>(parent.size(),-1);
      for (int i = 0; i < parent.size(); i++)
        u1[parent[i]].push_back(i);
    }
    
    bool lock(int num, int user) {
        if (locked[num] == -1)
        {
          locked[num] = user;
          return true;
        }
      return false;
    }
    
    bool unlock(int num, int user) {
        if (locked[num] == user)
        {
          locked[num] = -1;
          return true;
        }
      return false;
    }
    
    bool upgrade(int num, int user) {
        if (locked[num] != -1)
          return false;
      
      
      // cout << check_lower(num) << endl;
      // cout << check_upper(num) << endl;
       if (check_lower(num) && check_upper(num))
       {
         change_lower(num);
         lock(num,user);
         return true;
       }
      return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */