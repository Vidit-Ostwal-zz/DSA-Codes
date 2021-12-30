class Solution {
public:
  /*
  Time Complexity = O(N*N)
  Sapce Complixity = O(1)
  */
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0 ; i < image.size(); i++)
        {
          reverse(image[i].begin(),image[i].end());
          for (int j = 0; j < image[0].size() ; j++)
          {
            /*XOR Operator with 1 reverse the bit*/
            image[i][j] = image[i][j]^1; 
          }
        }
      return image;
    }
};