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
        int first = 0;
        int second = 0;

        vector<pair<char,int>> words;
        
        vector<string> numbers = {"zero","one","two","three","four","five","six","seven","eight","nine", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        for (const auto& number : numbers) {
            size_t pos = 0;
            while ((pos = s.find(number, pos)) != string::npos) {
                char digchar;
                if(number == "zero")
                {
                    digchar = '0';
                }else if(number == "one" || number == "1")
                {
                    digchar = '1';
                }else if(number == "two" || number == "2")
                {
                    digchar = '2';
                }else if(number == "three" || number == "3")
                {
                    digchar = '3';
                }else if(number == "four" || number == "4")
                {
                    digchar = '4';
                }else if(number == "five" || number == "5")
                {
                    digchar = '5';
                }else if(number == "six" || number == "6")
                {
                    digchar = '6';
                }else if(number == "seven" || number == "7")
                {
                    digchar = '7';
                }else if(number == "eight" || number == "8")
                {
                    digchar = '8';
                }else if(number == "nine" || number == "9")
                {
                    digchar = '9';
                }

                words.push_back(make_pair(digchar, pos));
                pos += number.length();
            }
        }

        sort(words.begin(), words.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        });

        first = words[0].first - '0';
        second = words[words.size()-1].first - '0';

        digit = 10 * first + second;
        // cout << digit << endl;
        sum += digit;
        
    }

    cout << sum << endl;

    return 0;
}