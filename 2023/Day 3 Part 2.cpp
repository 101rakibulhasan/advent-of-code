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
    vector<pair<ll,ll>> res;

    string ind;
    string ind_x = ".";
    string ind_y = ".";

    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            if(vec[i][j] >= '0' && vec[i][j] <= '9')
            {
                if(vec[i][j-1] == '*' && j > 0)
                {
                    ind_x = to_string(i);
                    ind_y = to_string(j-1);
                    // cout << "left" << endl;
                }

                if(j > 0 && i > 0 && vec[i-1][j-1] == '*')
                {
                    ind_x = to_string(i-1);
                    ind_y = to_string(j-1);
                    // cout << "left-top" << endl;
                }

                if(j > 0 && i+1 < vec.size() && vec[i+1][j-1] == '*')
                {
                    ind_x = to_string(i+1);
                    ind_y = to_string(j-1);
                    // cout << "left-bottom" << endl;
                }

                string digit_str;
                while(vec[i][j] >= '0' && vec[i][j] <= '9')
                {
                    digit_str += vec[i][j];
                    
                    if(i-1 >0 && vec[i-1][j] == '*') //&& (vec[i-1][j] > '9' || vec[i-1][j] < '0')
                    {
                        ind_x = to_string(i-1);
                        ind_y = to_string(j);
                        // cout << "top" << endl;
                    }

                    if(i+1 < vec.size() && vec[i+1][j] == '*')
                    {
                        ind_x = to_string(i+1);
                        ind_y = to_string(j);
                        // cout << "bottom" << endl;
                    }

                    j++; 
                }

                if(vec[i][j] == '*' && j < vec[i].size())
                {
                    ind_x = to_string(i);
                    ind_y = to_string(j);
                    cout << "right" << endl;
                }

                if(j < vec[i].size()-1 && i > 0 && vec[i-1][j] == '*')
                {
                    ind_x = to_string(i-1);
                    ind_y = to_string(j);
                    // cout << i-1<<j<<"right-top" << endl;
                }

                if(j < vec[i].size()-1 && i+1 < vec.size() && vec[i+1][j] == '*')
                {
                    ind_x = to_string(i+1);
                    ind_y = to_string(j);
                    // cout << i << j << "right-bottom" << endl;
                }

                // cout << digit_str << endl;
                // cout << ind_x << " " << ind_y << endl;
                ind = ind_x + ind_y;
                cout <<"IND: " <<ind << endl;
                if(ind == "..")
                {
                    ind = "00";
                }
                if(!digit_str.empty() && !ind.empty())
                {
                    res.push_back({stoi(digit_str), stoi(ind)});
                }
                ind = "";
                ind_x = ".";
                ind_y = ".";
                
                cout <<"DIGIT: "<<digit_str<< endl;
            }
        }
    }

    sort(res.begin(), res.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return a.second < b.second;
        });

        for(ll i =0; i<res.size()-1; i++)
        {
            if(res[i].second == res[i+1].second && res[i].second != 0)
            {
                sum += res[i].first * res[i+1].first;
                i++;
            }
        }

        cout << sum << endl;



        return 0;
}
