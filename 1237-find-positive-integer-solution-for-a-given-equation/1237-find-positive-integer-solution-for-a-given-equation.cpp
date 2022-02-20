/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
  /*Classical Binary Search return index if found, returns -1 if not found*/
  int Binary_Search(CustomFunction& customfunction, int st, int ed,int target,int x)
 {
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
    int temp = customfunction.f(x,mid);
   if (temp == target)
    return mid;
    
   if (temp > target)
    ed = mid - 1;
    
   else
    st = mid + 1;
  }
  return -1;
}
  
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
      /*vector<vector<int>> answer;
    for (int i = 1; i <= 1000; i++)
      for (int j = 1; j <= 1000; j++)
      {
        int temp = customfunction.f(i,j);
        if (temp == z)
        {
          vector<int> temp;
          temp.push_back(i);
          temp.push_back(j);
          answer.push_back(temp);
        }
      }
    return answer;
    }*/
      
      /*Decide x via loop and then do a binary search for y*/
      
      vector<vector<int>> final_vector;
      for (int x = 1; x <= 1000; x++)
      {
        int y = Binary_Search(customfunction,1,1000,z,x);
        if (y != -1)
          final_vector.push_back({x,y});
      }
      return final_vector;
    }
};