class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
      sort(nums.begin(),nums.end());
      
      for (int i = 0; i < nums.size(); i++)
        map[nums[i]].push_back(i);
      
      set<vector<int>> answer; 
      for (int i = 0 ;i < nums.size(); i++)
      {
        for (int j = i+1 ; j < nums.size(); j++)
        {
          int left = -1 * (nums[i] + nums[j]);
          
          for (int k = 0; k < map[left].size(); k++)
          {
            if (map[left][k] > j)
            {
              vector<int> f;
              f.push_back(nums[i]);
              f.push_back(nums[j]);
              f.push_back(nums[map[left][k]]);
              answer.insert(f);
              
              while (j +1 < nums.size() && nums[j] == nums[j+1])
                j++;
              
              break;
            }
          }
        }
        while (i +1 < nums.size() && nums[i] == nums[i+1])
                i++;
        
     
      }
      vector<vector<int>> final_a(answer.begin(),answer.end());
      return final_a;
    }
};