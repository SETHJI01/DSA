#include <bits/stdc++.h>
using namespace std;
int main()
{
    string txt, pt;
    cin >> txt >> pt;
    int n = txt.length(), m = pt.length();
    for (int i = 0; i <= n - m;)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (txt[i+j] != pt[j])
                break;
        }
        if (j == m)
            cout << i << " ";
        if (j == 0)
            i++;
        if (j != 0)
            i += j;
    }
}
