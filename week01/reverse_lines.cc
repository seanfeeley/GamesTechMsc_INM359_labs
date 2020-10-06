#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
        string s;
        vector<string> vs;
        while ( getline(cin, s) )
          {
            vs.insert(vs.begin(), s);
          }
        for (string si : vs) {
          cout<<si<<endl;
        }
        return 0;
}
