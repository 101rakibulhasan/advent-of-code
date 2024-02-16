#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

const ld pi = acos(-1);
const ll MOD = 1000000007;
const ll N = 1e5+7;

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    vector<string> vec;
    string s;
    while(getline(cin,s))
    {
        vec.push_back(s);
    }

    ll sum = 0;

    for(ll i = 0; i < vec.size(); i++)
    {
        vector<string> win;
        vector<string> hav;
        int flag = 0;
        for(unsigned long long j = 10; j < vec[i].size(); j++)
        {
            if(vec[i][j] == '|')
            {
                flag = 1;
                j+=1;
                continue;
            }

            string digit_str;
            
            digit_str += vec[i][j];
            digit_str += vec[i][j+1];

            // cout << digit_str << endl;

            if(flag == 0)
            {
                win.push_back(digit_str);
            }
            else
            {
                hav.push_back(digit_str);
            }

            j+=2;
        }

        ll _count = 0;
        for(ll k = 0; k < hav.size(); k++)
        {
            for(ll p = 0; p < win.size(); p++)
            {
                if(hav[k] == win[p])
                {
                    _count++;
                    // cout << win[p] << " ";
                }
            }
        }

        // cout << _count << endl;

        sum += pow(2,_count-1);
    }

    cout << sum << endl;

    return 0;
}