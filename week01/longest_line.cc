#include <string>
#include <iostream>
using namespace std;

int main() {
        string s, ls;
        while ( getline(cin, s) )
          {
            if (s.size() > ls.size()) ls = s;

          }
        cout<<ls<<endl;

        return 0;
}
