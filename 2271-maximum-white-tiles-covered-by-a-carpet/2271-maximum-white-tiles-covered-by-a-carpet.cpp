class Solution {
//   {
//        sort(tiles1.begin(),tiles1.end());
//       vector<vector<int>> tiles;
      
//       for (int i = 0; i < tiles1.size(); i++)
//       {
//         if (tiles.size() == 0)
//           tiles.push_back(tiles1[0]);
//         else if (tiles1[i][0] - 1 == tiles[tiles.size()-1][1])
//           tiles[tiles.size()-1][1] = tiles1[i][1];
//         else
//           tiles.push_back(tiles1[i]);
//       }
//        // cout << tiles.size() << endl;
     
      
      
//       vector<int> st;
//       vector<int> ed;
//       int mini = INT_MAX;
//       int maxi = -1;
//       int answer = 0;
//       int sum = 0;
//       int I = 0;
//       int J = 0;
      
//       for (int i = 0; i < tiles.size(); i++)
//       {
//         st.push_back(tiles[i][0]);
//         ed.push_back(tiles[i][1]);
        
//         mini = min(mini,tiles[i][0]);
//         maxi = max(maxi,tiles[i][1]);
//       }
      
//       int j = mini;
//       int i = mini;
      
//       for (i = mini; i <= maxi && i < mini + carpetLen; i++)
//       {
//         if (i < st[I])
//         {}
//         else if (i >= st[I] && i <= ed[I])
//           sum++;
//         else
//         {
//           cout << i << "    " << sum << endl;
//            I++;
//         }
        
//       }
      
//       answer = max(answer,sum);
//       for (; i <= maxi ;i++)
//       {
//         if (i < st[I])
//         {}
//         else if (i >= st[I] && i <= ed[I])
//           sum++;
//         else
//         {
//           I++;
//         }
        
//         if (j < st[J])
//         {}
//         else if (j >= st[J] && j <= ed[J])
//           sum--;
//         else
//           J++;
        
//         j++;
//         answer = max(answer,sum);
//       }
//       return answer;
//     }
  
  // Easy because of non overlapping problem
public:  
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) 
  {
    vector<int> prefix_sum;
    vector<int> start;
    vector<int> end;
    sort(tiles.begin(),tiles.end());
    int maxi = 0;
    
    for (int i=  0; i < tiles.size(); i++)
    {
      start.push_back(tiles[i][0]);
      end.push_back(tiles[i][1]);
      
      int temp_sum = tiles[i][1] - tiles[i][0]+1;
      
      if (prefix_sum.size() == 0)
        prefix_sum.push_back(temp_sum);
      else
        prefix_sum.push_back(prefix_sum[i-1]+temp_sum);
      // cout << prefix_sum[i] << "    " ;
    }
    // cout << endl;
    // Now we need to check from the starting of each tiles carpet what will be the maximum tiles covered.
    
    for (int i = 0; i < tiles.size(); i++)
    {
      int st = tiles[i][0];
      // ed Inclusive
      int ed = st + carpetLen - 1;
      
      int index = lower_bound(start.begin(),start.end(),ed) - start.begin();
      // cout << index << endl;
      
      if (index < end.size() && end[index] == ed)
        index++;
      
      index--;
      
      int temp = prefix_sum[index] - ((i > 0) ? prefix_sum[i-1] : 0);
      // cout << "Temp    " << temp << endl;
      //now index will either have the ed in it or ed will cover it and not covering the next index;
      
      if (end[index] > ed)
      {
        int po = end[index] - ed;
        temp -= po;
      }
      maxi = max(maxi,temp);
    }
    return maxi;
  }
};