#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

const ld pi = acos(-1);
const ll MOD = 1000000007;
const ll N = 1e5+7;

int

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    int tc = 1000;
    ll sum = 0;
    for(int i = 0; i < tc; i++)
    {
        string s; cin >> s;
        int digit = 0;
        int first = -1;
        int second = 0;

        for(ll i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                if(first == -1)
                {
                    first = s[i] - '0';
                }
                
                second = s[i] - '0';   
            }
        }

        digit = 10 * first + second;
        cout << digit << endl;
        sum += digit;
        
    }

    cout << sum << endl;

    return 0;
}