class Solution {
  void Show_Map(unordered_map<int,int> map)
  {
    auto it  = map.begin();
    
    cout << "Printing Map" << endl;
    cout << "-----------------" << endl;
    cout << "Key" << "      " << "Value" << endl;
    
    while (it != map.end())
    {
      cout << it-> first << "     " << it -> second << endl;
      it++;
    }
    
    cout << "Printing Map Over" << endl;
  }
  
public:
    int minOperations(vector<int>& nums, int x) {
      int sum = 0;
      int answer = -1;
      
      for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
      
      if (sum == x)
        return nums.size();
      
      int req_sum = sum-x;
      
      unordered_map<int,int> map1;
      map1[0] = -1;
      sum = 0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        sum += nums[i];
        int RR = sum - req_sum;
        
        if (map1.find(RR) != map1.end())
        {
          // cout << RR << endl;
          answer = max(answer,i-map1[RR]);
        }
        map1[sum] = i;
        // cout << answer << "     " << RR << endl;
      }
      // Show_Map(map1);
      return (answer == -1) ? -1 : nums.size() - answer ;
    }
};