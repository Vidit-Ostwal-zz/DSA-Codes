class Solution {
public:
  
  /*
  Space Complexity = O(N)
  making recursive N function calls
  
  Time Complexity = O(N)
  Like an interation we are going forward
  */
  /*Get the count of all different permutations*/
  int count_all_permutations(int n)
  {
    int count = 1;
    int i = 1;
    while (i < n)
    {
      count = count * i;
      i++;
    }
    return count;
  }
  
  
  string findkthpermutation(int n, int k, vector<int>temp_vector)
  { 
    if (n == 0)
    {
      return "";
    }
    
    int one_for_each = count_all_permutations(n);
    int particular_index = (k - 1)/one_for_each;
   
    string final_string = to_string(temp_vector[particular_index]);
 
    temp_vector.erase(temp_vector.begin() + particular_index);
    return final_string + findkthpermutation(n-1,k - particular_index*one_for_each,temp_vector);
  }
  
  
  
    string getPermutation(int n, int k) {
      vector<int> temp_vector;
      for (int i = 1 ; i <= n; i++)
      {
        temp_vector.push_back(i);
      }
      return findkthpermutation (n,k, temp_vector);
    }
};