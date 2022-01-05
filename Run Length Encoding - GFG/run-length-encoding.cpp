// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  int start = 0;
  string answer = "";
  while (start < src.length())
 {
     
     char temp = src[start];
     int count = 0;
     while (start < src.length() && src[start] == temp )
     {
         count++;
         start++;
     }
     
     answer += temp + to_string(count);
 }
 return answer;
}     
 
