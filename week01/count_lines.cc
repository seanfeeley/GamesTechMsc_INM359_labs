#include <string>
#include <iostream>
using namespace std;

int main() {
        int c;
        string s;
        c = 0;
        while ( getline(cin, s) ) c++;
        cout<<c<<endl;

        return 0;
}
