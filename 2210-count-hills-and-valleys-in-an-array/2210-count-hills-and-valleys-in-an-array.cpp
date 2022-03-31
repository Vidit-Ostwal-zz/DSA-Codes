class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> hills;
      vector<int> valleys;
      
      for (int i = 1; i < nums.size()-1; i++)
      {
        int st = i;
        int ed = i;
        
        while (st>=0 && nums[st] == nums[i])
          st--;
        
        while (ed < nums.size() && nums[ed] == nums[i])
          ed++;
        
        if (st >= 0 && ed < nums.size())
        {
          if (nums[i] > nums[st] && nums[i] > nums[ed])
            hills.push_back(i);
          
          if (nums[i] < nums[st] && nums[i] < nums[ed])
            valleys.push_back(i);
        }
      }
      
        cout << "HEllo" << endl;
      int count = 0;
        for (int i = 1; i < hills.size(); i++)
        {
          cout << hills[i] << "  " ;
          if (hills[i] - hills[i-1] == 1)
            count++;
        }
        cout << endl;
        
        for (int i = 1; i < valleys.size(); i++)
        {
          cout << valleys[i] << "  ";
          if (valleys[i] - valleys[i-1] == 1)
            count++;
        }
        cout << endl;
      
      
      return hills.size() + valleys.size() - count;
    }
};