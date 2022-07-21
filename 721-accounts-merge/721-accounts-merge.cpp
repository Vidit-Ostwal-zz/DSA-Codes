 class DisjointSetUnion
 {
     public:
         int n;
     vector<int> parent;
     vector<int> rank;

     DisjointSetUnion(int size)
     {
         n = size;
         parent = vector<int> (n, 0);
         rank = vector<int> (n, 0);

         for (int i = 0; i < parent.size(); i++)
             parent[i] = i;
     }

     int get_parent(int n)
     {
         if (parent[n] == n)
             return n;
         return parent[n] = get_parent(parent[n]);
     }

     bool union_by_rank(int x, int y)
     {
         x = get_parent(x);
         y = get_parent(y);

         if (x == y)
             return false;
         else if (rank[x] > rank[y])
             parent[y] = x;
         else if (rank[y] > rank[x])
             parent[x] = y;
         else
         {
             parent[y] = x;
             rank[x]++;
         }
         return true;
     }

     int countcomponents()
     {
         set<int> parentset;
         for (int i = 0; i < parent.size(); i++)
             parentset.insert(get_parent(i));

         return parentset.size();
     }
 };

void show_vector(vector<int> vect)
{
  for (auto&it:vect)
  {
    cout << it << endl;
    // cout << it.first << "  " << it.second << endl;
  }
}

 class Solution
 {
     public:
         vector<vector < string>> accountsMerge(vector<vector < string>> &accounts)
         {

             unordered_map<string, vector < int>> mapping;
             int n = accounts.size();

             DisjointSetUnion DSG(n);

             for (int i = 0; i < accounts.size(); i++)
                 for (int j = 1; j < accounts[i].size(); j++)
                     mapping[accounts[i][j]].push_back(i);

             auto it = mapping.begin();

             while (it != mapping.end())
             {
                 vector<int> temp = it->second;

                 for (int i = 1; i < temp.size(); i++)
                     DSG.union_by_rank(temp[0], temp[i]);

                 it++;
             }

             vector<int> PARENT = DSG.parent;
           
           unordered_map<int,map<string,int>> map_accounts;
           // show_vector(PARENT);
           
           for (int i = 0; i < PARENT.size(); i++)
           {
             int index = DSG.get_parent(PARENT[i]);
             
             for (int j = 1; j < accounts[i].size(); j++)
               map_accounts[index][accounts[i][j]]++;
           }
           
           vector<vector<string>> answer;
           
           auto it1 = map_accounts.begin();
           
           while (it1 != map_accounts.end())
           {
             auto it2 = it1 -> second.begin();
             int index = it1 -> first;
             vector<string> temp;
             temp.push_back(accounts[index][0]);
             
             while (it2 != it1-> second.end())
             {
               temp.push_back(it2 -> first);
               it2++;
             }
             it1++;
             answer.push_back(temp);
           }
           return answer;
         }
 };