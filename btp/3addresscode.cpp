#include <bits/stdc++.h>
using namespace std;
vector<string> res;
int j = 0;
vector<string> D = {"Z", "X", "Y", "W", "V", "U", "T", "S", "R", "Q", "P"};
void generate(string s)
{
    if (s.length() == 0)
        return;
    if (s.length() == 1)
        return;
    bool flag = false;
    bool flag2 = false;
    string temp = "";
    string k = "";
    string t1 = "";
    string t2 = "";
    for (auto it : s)
    {
        if (flag == false && flag2 == false)
            t1 += it;
        if (flag2 == true)
            t2 += it;
        if (it == ')')
        {
            flag2 = true;
            flag = false;
        }
        if (flag == true)
        {
            temp += it;
        }
        if (it == '(')
        {
            flag = true;
        }
    }
    if (temp != "")
    {
        generate(temp);
        s = t1.substr(0, t1.size() - 1) + res[res.size() - 1][0] + t2;
    }
    temp = "";
    k = "";
    if (s[0] == '-')
    {
        string x = D[j];
        temp = x + '=' + '-' + s[1];
        res.push_back(temp);
        s = x + s.substr(2, s.size() - 2);
        j++;
        generate(s);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (i > 0 && (s[i - 1] == '=' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '+' || s[i - 1] == '-') && s[i] == '-')
        {
            string x = D[j];
            temp = x + '=' + '-' + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '%')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '/')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    if (s[1] == '=')
        res.push_back(s);
}
void show()
{
    for (auto it : res)
    {
        cout << it << endl;
    }
}
int main()
{
    int t = 1;
    while (t--)
    {
        string s;
        cout << "Enter a expression" << endl;
        cin >> s;
        generate(s);
        show();
        res.clear();
    }
    return 0;
}