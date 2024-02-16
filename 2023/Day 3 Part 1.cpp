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
    while (getline(cin, s))
    {
        vec.push_back(s);
    }

    ll sum = 0;

    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            if(vec[i][j] >= '0' && vec[i][j] <= '9')
            {
                int flag = 0;
                if(vec[i][j-1] != '.' && (vec[i][j-1] > '9' || vec[i][j-1] < '0') && j > 0)
                {
                    flag = 1;
                    //cout << "left" << endl;
                }

                if(j > 0 && i > 0 && vec[i-1][j-1] != '.' && (vec[i][j-1] > '9' || vec[i][j-1] < '0'))
                {
                    flag = 1;
                    //cout << "left-top" << endl;
                }

                if(j > 0 && i+1 < vec.size() && vec[i+1][j-1] != '.' && (vec[i][j-1] > '9' || vec[i][j-1] < '0'))
                {
                    flag = 1;
                    //cout << "left-bottom" << endl;
                }

                string digit_str;
                while(vec[i][j] >= '0' && vec[i][j] <= '9')
                {
                    digit_str += vec[i][j];
                    
                    if(i-1 >0 && vec[i-1][j] != '.' && flag == 0 && (vec[i-1][j] > '9' || vec[i-1][j] < '0')) //&& (vec[i-1][j] > '9' || vec[i-1][j] < '0')
                    {
                        flag = 1;
                        //cout << "top" << endl;
                    }

                    if(i+1 < vec.size() && vec[i+1][j] != '.' && flag == 0 && (vec[i+1][j] > '9' || vec[i+1][j] < '0'))
                    {
                        flag = 1;
                        //cout << "bottom" << endl;
                    }

                    j++; 
                }

                if(vec[i][j] != '.' && (vec[i][j] > '9' || vec[i][j] < '0') && j < 140)
                {
                    flag = 1;
                    //cout << "right" << endl;
                }

                if(j < vec[i].size()-1 && i > 0 && vec[i-1][j] != '.')
                {
                    flag = 1;
                    //cout << i-1<<j<<"right-top" << endl;
                }

                if(j < vec[i].size()-1 && i+1 < vec.size() && vec[i+1][j] != '.')
                {
                    flag = 1;
                    //cout << i << j << "right-bottom" << endl;
                }

                if(flag == 1)
                {
                    // cout << digit_str << endl;
                    sum += stoi(digit_str);
                    flag = 0;
                }

                //cout <<digit_str<< endl;
            }
        }
    }

    

    cout << sum << endl;

    return 0;
}