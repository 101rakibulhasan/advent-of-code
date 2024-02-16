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

    ll tc = 100;
    ll sum = 0;
    
    while(tc--)
    {
        ll target_red = 12;
        ll target_green = 13;
        ll target_blue = 14;

        ll sum_red = 0;
        ll sum_green = 0;
        ll sum_blue = 0;

        string s; 
        getline(cin, s);

        ll pos = 0;
        string pos_str;
        ll start = 5;
        while(s[start] <= '9' && s[start] >= '0')
        {
            pos_str += s[start];
            start++;
        }

        pos = stoi(pos_str);

        string digit_str;
        ll digit;

        for(ll i = start; i < s.size(); i++)
        {
            while(s[i] <= '9' && s[i] >= '0')
            {
                digit_str += s[i];
                i++;
            }

            if(!digit_str.empty())
            {
                i++;
                digit = stoi(digit_str);
                // cout << s[i] << endl;
            
                if(s[i] == 'r')
                {
                    sum_red = max(sum_red,digit);
                    i+= 3;
                }else if(s[i] == 'g')   
                {
                    sum_green = max(sum_green,digit);
                    i+= 5;
                }else if(s[i] == 'b')
                {
                    sum_blue = max(sum_blue,digit);
                    i+= 4;
                }
                digit_str = "";
            }
        }

        // cout << "Red: " <<sum_red << endl;
        // cout << "Green: " <<sum_green << endl;
        // cout << "Blue: " <<sum_blue << endl;

        sum += (sum_red * sum_green * sum_blue);
         
    }
    cout << sum << endl;

    return 0;
}