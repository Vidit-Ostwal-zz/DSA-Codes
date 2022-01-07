class Solution {
public:
  /*
  Time Complexity = O(N^2)
  Space Complexity = O(N)
  */
  vector<int> brute_force (vector<int>& nums1){
    vector<int> temp_vector;
    for (int i = 0; i < nums1.size(); i++)
    {
      int j = i+1;
      cout << i << "  " << j << endl;
      while(j < nums1.size() && nums1[j] <= nums1[i])
      {
        j++;
      }
      if (j == nums1.size())
      {
        j = 0;
        while(j < i && nums1[j] <= nums1[i])
        {
          j++;
        }
      }
      if(j == nums1.size() || j == i)
      {
        temp_vector.push_back(-1);
      }
      else
      {
        temp_vector.push_back(nums1[j]);
      }
    }
    return temp_vector;
  }
  
    vector<int> nextGreaterElements(vector<int>& nums) {
        return brute_force(nums);
    }
};