class Solution {
public:
  
  /*
  Time Complexity = O(N*M)
  Space Complexity = O(N)
  */
  vector<int> brute_force (vector<int>& nums1, vector<int>& nums2){
    vector<int> temp_vector;
    for (int i = 0 ; i < nums1.size(); i++)
    {
      int index = 0;
      while (nums2[index] != nums1[i])
      {
        index++;
      }
      int temp_number = nums1[i];
      index++;
      while (index < nums2.size() && temp_number > nums2[index])
      {
        index++;
      }
      if (index == nums2.size())
      {
        temp_vector.push_back(-1);
      }
      else
      {
        temp_vector.push_back(nums2[index]);
      }
    }
    return temp_vector;
  }
  
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return brute_force(nums1,nums2);
    }
};