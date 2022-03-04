class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> temp_vector(query_row+1,vector<double>(query_row+1,double(0)));
      temp_vector[0][0] = poured;
      int i = 1;
      while (i <= query_row)
      {
        for (int j = 0; j <= i;j++)
        {
          if (j == 0)
          {
            temp_vector[i][j] = max(double(0),(temp_vector[i-1][j] - 1)/ double(2));
            cout << (temp_vector[i-1][j] - 1)/ double(2) << endl;
          }
          
          else if (j == i)
          {
            temp_vector[i][j] = max(double(0),(temp_vector[i-1][j-1] - 1)/double(2));
            cout << (temp_vector[i-1][j-1] - 1)/double(2) << endl;
          }
          
          else
            temp_vector[i][j] = max(double(0),(temp_vector[i-1][j] - 1)/ double(2)) + max(double(0),(temp_vector[i-1][j-1] - 1)/double(2));
        }
        i++;
        cout << endl;
      }
      return min(double(1),temp_vector[query_row][query_glass]);
    }
};