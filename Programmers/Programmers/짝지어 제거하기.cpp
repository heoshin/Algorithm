#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    if (s.length() % 2 != 0) return 0;
    stack<char> st;
    int pt = 0;
    st.push(0);
    while (pt < s.length())
    {
        for (; pt < s.length() && s[pt] == s[pt + 1]; pt += 2);
        for (; pt < s.length() && s[pt] != st.top(); ++pt) st.push(s[pt]);
        for (; pt < s.length() && s[pt] == st.top(); ++pt) st.pop();
    }
    return st.size() == 1;
    /*int EraseCnt = 0;
    int LeftIdx = 0, RightIdx = -1;
    while (true)
    {
        bool bFind = false;
        for (int i = RightIdx + 1; i < s.length() - 1; ++i)
        {
            if (s.at(i) == s.at(i + 1))
            {
                bFind = true;
                LeftIdx = i;
                RightIdx = i + 1;
                break;
            }
        }
        if (!bFind) break;


        for (; !(LeftIdx <= 0 || RightIdx >= s.length() - 1) &&
            s.at(LeftIdx - 1) == s.at(RightIdx + 1); --LeftIdx, ++RightIdx);

        EraseCnt += RightIdx - LeftIdx + 1;
        printf("%d %d\n", LeftIdx, RightIdx);
    }
    printf("%d\n", EraseCnt);*/
    return 0;
}

int main()
{
    string s = "aa";
    while (true)
    {
        cin >> s;
        int result = solution(s);
        cout << result << "\n";
    }
    /*s = "cdcd";
    result = solution(s);
    cout << result << "\n";*/
}