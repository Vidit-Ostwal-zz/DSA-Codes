class Solution {
  int Binary_Search(vector<int> temp, int k,bool flag)
  {
    int start = 0;
    int end = temp.size()-1;
    
    while (start <= end)
    {
      int mid = start + (end-start)/2;
      if (temp[mid] == k)
        return mid;
      
      if (temp[mid] > k)
        end = mid -1;
      
      else
        start = mid+1;
    }
    return (flag) ? start : end;
  }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
      int count = 0;
      for (int i = 0; i < arr1.size(); i++)
      {
        /*a should be smaller*/
        int a = arr1[i] - d ;
        int b = arr1[i] + d ;
        
        if (a > b)
        {
          int temp = b;
          b = a;
          a = temp;
        }
        /* a is smaller and b is bigger */
        int small = Binary_Search(arr2,a,true);
        int bigger = Binary_Search(arr2,b,false);
        cout << a << b << small << bigger << endl;
        if (bigger - small >= 0)
          count++;
      }
      return arr1.size() - count;
    }
};