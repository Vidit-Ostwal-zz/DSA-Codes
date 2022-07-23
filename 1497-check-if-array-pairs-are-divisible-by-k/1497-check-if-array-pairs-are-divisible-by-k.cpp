class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
      // We first need to change the argument into which is going to divide which one
      
      map<int,int> map1;
      
      for (int i = 0; i < arr.size(); i++)
      {
        cout << ((arr[i] % k) + k)%k<< endl;
        map1[((arr[i] % k) + k)%k]++;
      }
      
      auto it = map1.begin();
      
      while (it != map1.end())
      {
        if (it -> first == 0)
        {
          if (it -> second % 2)
            return false;
        }
        else
        {
          int element  = it -> second;
          int req = k - it->first;
          
          if (map1[req] != element)
            return false;
        }
        it++;
      }
      return true;
    }
};