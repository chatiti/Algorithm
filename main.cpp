#include <bits/stdc++.h>

using namespace std;

int main()
{

    map<int, int> m;
    m[1] = 1;
    m[2] = 2;
    for (auto i = m.begin(); i != m.end(); ++i)
    {
        cout << i->first << endl;
    }
    cout << m[2] << endl;
    return 0;
}