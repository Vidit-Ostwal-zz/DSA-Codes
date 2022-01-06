class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      vector<int> final_vector;  
      if (nums1.size() < nums2.size())
        {
          for (int i = 0; i< nums1.size(); i++)
          {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            if(it != nums2.end())
            {
              final_vector.push_back(nums1[i]);
              nums2.erase(it);
            }
          }
        }
      else
      {
        for (int i = 0; i< nums2.size(); i++)
          {
            auto it = find(nums1.begin(), nums1.end(), nums2[i]);
            if(it != nums1.end())
            {
              final_vector.push_back(nums2[i]);
              nums1.erase(it);
            }
          }
      }
      return final_vector;
    }
};