class Solution {
public:
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
  
  
    vector<int> getRow(int rowIndex) {
      vector<int> row_1 = {1};
      
      for (int i = 0 ; i< rowIndex;i++)
        row_1 = make_new_row(row_1);
      
      return row_1;

    }
};