class Solution {
  // vector<int> temp;
  
//   void recur(vector<int> nums, int in, vector<int> fv)
//   {
//     if (in == nums.size())
//     {
//       if (fv.size() > temp.size())
//         temp = vector<int>(fv.begin(),fv.end());
      
//       return;
//     }
    
//     recur(nums,in+1,fv);
    
//     if (nums[in] % fv[fv.size()-1] == 0)
//     {
//       fv.push_back(nums[in]);
//       recur(nums,in+1,fv);
//     }
//   }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      
      // for (int i = 0; i < nums.size(); i++)
      //   recur(nums,i+1,{nums[i]});
      unordered_map<int,vector<int>> u1;
      
      vector<int> gl;
      for (int i = 0; i < nums.size() ; i++)
      {
        int index = -1;
        int vec_ln = -1;
        int j = i - 1; 
        
        while (j >= 0)
        {
          // cout << i << "     " << j << endl; 
          // cout << nums[i] % nums[j] << endl;
          if ((nums[i] % nums[j]) == 0)
          {
            // cout << u1[j].size() << endl;
            if (vec_ln <  (int)u1[j].size())
            {
              vec_ln = u1[j].size();
              index = j;
            }
          }
          j--;
        }
        
       // / cout << "Index  " << index << endl;
       
        if (index < 0)
          u1[i].push_back(nums[i]);
        else
        {
          vector<int> temp = vector<int>(u1[index].begin(),u1[index].end());
          temp.push_back(nums[i]);
          u1[i] = vector<int>(temp.begin(),temp.end());
        }
        
        // cout << u1[i].size() << endl;
        
        if (gl.size() < u1[i].size())
          gl = vector<int>(u1[i].begin(),u1[i].end());
      }
      
      return gl;
    }
};