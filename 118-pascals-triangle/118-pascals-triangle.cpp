class Solution {
public:
  
  /*size of row is the row_number*/
  /*Time Complexity = O(N) + O(N-1) .....  = O(N*N)
  Space Complexity = O(N*N)
  */
  vector<int> make_new_row (vector<int> prev_row)
  {
    vector<int> final_vector;
    
    for (int i = 0; i < prev_row.size(); i++)
    {
      if (i == 0)
        final_vector.push_back(prev_row[i]);
      
      if ( i > 0 )
        final_vector.push_back(prev_row[i] + prev_row[i-1]);
      
      
      if (i == prev_row.size() -1)
        final_vector.push_back(prev_row[i]); 
    }
    
    return final_vector;
  }
  
  
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> final_vector ;
      vector<int> row_1 = {1};
      final_vector.push_back(row_1);

      
      for (int i = 0 ; i< numRows-1;i++)
        final_vector.push_back(make_new_row(final_vector[i]));

      return final_vector;
    }
  
};