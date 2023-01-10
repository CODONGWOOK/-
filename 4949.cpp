#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void)
{
	fastio();


  while(1)
  {
    string s;
    getline(cin, s);
    if(s == ".") break;
    stack<char> st;
    bool check = true;
    for(auto c : s){
      if(c == '(' || c == '[')
          st.push(c);
      else if(c == ')')
      {
        if(st.empty() || st.top() != '(')
        {
          check = false;
          break;
        }
        st.pop();
      }
      else if(c == ']')
      {
        if(st.empty() || st.top() != '[')
        {
          check = false;
          break;
        }
        st.pop();
      }
    }
    if(!st.empty())
        check = false;

    if(check) 
        cout << "yes\n";
    else 
        cout << "no\n";
  }

}
/*



*/

