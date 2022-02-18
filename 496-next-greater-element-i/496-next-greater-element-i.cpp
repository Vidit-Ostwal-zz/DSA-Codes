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
  
  /*
  Efficient Hash Map
  Time Complexity = O(N)
  Sapce Complexity = O(N)*/
  
  vector<int> optimized_solution(vector<int>& nums1, vector<int>& nums2)
  {
    stack<int> st;
    vector<int> result;
    unordered_map <int,int> map;
    
    for (int i = nums2.size()-1 ; i >= 0; i--)
    {
      while (!st.empty() && nums2[i] > st.top())
        st.pop();
      
      if (st.empty())
        map[nums2[i]] = -1;
      
      else
        map[nums2[i]] = st.top();
      
      st.push(nums2[i]);
    }
    for (int i = 0 ;i < nums1.size(); i ++)
    {
      result.push_back(map[nums1[i]]);
    }
    return result;
  }
  
  
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      return optimized_solution(nums1,nums2);
    }
};