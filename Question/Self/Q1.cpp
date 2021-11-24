/* Q1 > Skip all the 'a' characters from a string and return the new string /vector of it */


#include <iostream>
#include <vector>
using namespace std;

/* Print function just to check the final result*/
void print(vector<char> print_vector)
{
    for (int i= 0; i < print_vector.size();i++)
    {
        cout << print_vector[i] << " ";
    }
}


/* Required char are printed via recursion
- Base condition with return when index is equal to characters size
- otherwise print when required char is not equal and then call a new recursion */
void printskipachar(string characters,int index)
{
  if (index == characters.length())
  {
    return;
  }
  
  char char1  = characters[index];
  if (char1 != 'a')
  {
    cout << char1;  
  }
  printskipachar(characters,index+1);
}

/* returns a char vector, but uses approach of processed and unproccesed, answer vector is also passed in the recursion call so
- base condition index equals character length return the answer vector
- a last return is also required on the recursion call
also can be done when function is void as answer vector is passed via pointer and not a copy*/
vector<char> printskipachar1(string characters,int index,vector<char>&answer)
{
  if (index == characters.length())
  {
    return answer;
  }
  
  char char1  = characters[index];
  if (char1 != 'a')
  {
    answer.push_back(char1);
  }
  return printskipachar1(characters,index+1,answer);
}


/* Here no answer vector call in recursion call
- Base condition return a empty vector
Every call make a new vector add current answer call to it
makes another vector and calls a recursion on it, add those two vector and then return the whole vector
add current answer and also the next recursion call and then return it.
*/
vector<char> printskipachar2(string characters,int index)
{
  if (index == characters.length())
  {
    return {};
  }
  vector <char> answer;
  
  char char1  = characters[index];
  if (char1 != 'a')
  {
    answer.push_back(char1);
  }
  vector<char> answer1 = printskipachar2(characters,index+1);
  answer.insert(answer.end(),answer1.begin(),answer1.end());
  return answer;
  
}

int main()
{
    vector <char> answer1  = printskipachar2("bcaabc",0);
    print(answer1);
}
