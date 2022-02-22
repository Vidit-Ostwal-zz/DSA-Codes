class Solution {
  /*all permutation count for less length*/
  int previous(string columnTitle)
  {
    int size = columnTitle.length()-1;
    int count = 0;
    
    while (size)
    {
      count += pow(26,size);
      size--;
    }
    return count;
  }
public:
    int titleToNumber(string columnTitle) {
        int temp1 = previous(columnTitle);
      
      int i  =0; 
      while (i < columnTitle.length())
      {
        if (i == columnTitle.length() - 1)
          temp1 += (columnTitle[i] - 'A') + 1;
        else
          temp1 += (columnTitle[i] - 'A') * pow(26,columnTitle.length() -1 -i);
        
        i++;
      }
      return temp1;
    }
};