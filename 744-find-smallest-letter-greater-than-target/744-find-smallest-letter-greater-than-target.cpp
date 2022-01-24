class Solution {
  char binary_search(vector<char> letters, char target)
  {
    int start = 0;
    int end =  letters.size()-1;
    
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      
      if (letters[mid] == target)
      {
        while (mid < letters.size() && letters[mid] == target)
        {
          mid++;
        }
        return letters[mid%letters.size()];
      }
      else if (letters[mid] - 'a' > target - 'a')
      {
        end = mid - 1;
      }
      else
      {
        start  = mid + 1;
      }
    }
    return letters[start%letters.size()];
  }
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        return binary_search(letters,target);
    }
};