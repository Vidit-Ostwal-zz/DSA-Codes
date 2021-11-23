/*
A pivot is chosen, and after the first pass, all the elements lesser than pivot go to the left side of pivot and all the elements bigger than pivot are on the right side of pivot, In easier manner, the pivot element comes at it’s right position.
In merge sort, even if the half side is sorted it will go to the very end, in this case this will not happen.
Complexity Analysis:

T(n) = T(k) + T(n-k-1) + O(n)
Worst Case: k = 0 when choosing rightmost or leftmost element
Time complexity for this case  = O(n2)

Best Case :dividing into two
T(n) = 2T(n/2) + O(n)
Time Complexity for this case  = O(nlogn)

Not Stable 
Space Complexity O(1)

Explanation or thinking:
Two pointers each starting from two different ends, when we complete first loop pivot element will be at right place, and two pointers will be needed for one both adjacent to side of pivot, these two pointers thus need to cross the pivot element, and then become the cutting index of son’s vector. 
Two while loop with only < > inequality makes sure that none of the pointers crosses the pivot and they both will cross the pivot at the same time. The equal equality in the swapping function makes sure that when both the pointers are at the pivot, then crosses each other. 
*/

class Solution {
public:

  void QuickSort(vector<int>& nums, int low, int high)
  {
    /*Base Condition*/
    if (low>= high)
      return;
    
    int start = low;
    int end = high;
    int mid  = low + (high - low)/2;
    int pivot = nums[mid];
    
    while (start <= end)
    {
      
      while (nums[start] < pivot)
      {
        start++;
      }
      while (nums[end] > pivot)
      {
        end--;
      }
      /*Neccessary check could have been that they have crossed*/
      if (start <= end)
      {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end]=  temp;
        start++;
        end--;
      }
    }
    cout << endl; 
      /* Now pivot is at right position, sort two side arrays*/
      QuickSort(nums, low, end);
      QuickSort(nums, start, high);
    }
  
  
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0,nums.size()-1);
      return nums;
    }
};
