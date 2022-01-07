class Solution {
public:
  void helper_function(vector<int>& arr, int index)
  {
    int temp;
    int prev = arr[index];
    for (int i = index + 1 ; i < arr.size(); i++)
    {
      temp = prev;
      prev = arr[i];
      arr[i] = temp;
    }
  }
  
  
  
  
    void duplicateZeros(vector<int>& arr) {
      for (int i = 0 ;i < arr.size(); i++)
      {
        if (!arr[i])
        {
          helper_function(arr,i);
          i++;
        }
      }
    }
};