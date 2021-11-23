/*
Vector is divided before calling the merge function. 
A new result vector is made in merge option every time.
*/

class Solution {
public:
  
  /* Merge Sort
  Time Complexity  = O(N*log(N)) for all the three cases
  Space Complexity = O(N) Because we are making 
  */
  
  
  vector<int> merge (vector<int>& left, vector<int>& right)
  {
    /* Takes cares of only merging the two vectors nothing else */
    /* Initializing the final vector Sorted with length of both the small vector*/
    vector<int> sorted(left.size() + right.size());
    int a = 0;
    int b = 0;
    int k = 0;
    
    while(a < left.size() && b < right.size())
    {
      if (left[a] < right[b])
      {
        sorted[k] = left[a];
        a++;
      }
      else
      {
        sorted[k] = right[b];
        b++;
      }
      k++;
    }
    
    while (a < left.size())
    {
      sorted[k] = left[a];
      k++;
      a++;
    }
    
    while (b < right.size())
    {
      sorted[k] = right[b];
      k++;
      b++;
    }
    return sorted;
  }
  
  
  vector<int> merge_sort (vector<int>& unsorted_array)
  {
    if (unsorted_array.size() == 1)
    {
      return unsorted_array;
    }
    
    int mid1 = unsorted_array.size()/2;
    
    auto mid = unsorted_array.begin() + mid1;
    
    /* Making the temporary vector left vector and right vector before passing it to merge function */
    vector<int> temp_left(mid1);
    vector<int> temp_right(unsorted_array.size() - mid1);

    copy(unsorted_array.begin(), mid, temp_left.begin());
    copy(mid, unsorted_array.end(), temp_right.begin());
 
    vector<int> left = merge_sort(temp_left);
    vector<int> right = merge_sort(temp_right);
    return merge(left,right);
  }
  
    vector<int> sortArray(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      return nums;
    }
};
