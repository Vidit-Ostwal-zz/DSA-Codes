/* See the workflow we can copy the intialized vector add some elements to it and then again push_back them to other the initialized vector*/


#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<string>> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size();j++)
        {
            cout << answer[i][j] ;
        }
        cout << endl;
    }
}

vector<vector<string>> get_subsets_iterative(vector<string> str)
{
    vector<vector<string>> final_vector = {{}};
    
    for (int i = 0 ; i < str.size(); i++)
    {
        vector<vector<string>> temp_vector(final_vector.begin(),final_vector.end());
        for(int j = 0; j < temp_vector.size();j++)
        {
            vector<string> temp_string = temp_vector[j];
            temp_string.push_back(str[i]);
            final_vector.push_back(temp_string);
        }
    }
    return final_vector;
}


int main()
{
   vector<string> str = {"a","b","c","d"};
   print(get_subsets_iterative(str));
}
