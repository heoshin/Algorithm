#include <iostream>
using namespace std;

int GetGCD(int a, int b)
{
    for (int i = min(a, b); i > 0; --i)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
}
long long solution(int w, int h) {
    long long answer = 1;

    int GCD = GetGCD(w, h);

    return (long long)w * h - (long long)((w + h) / GCD - 1) * GCD;
}

int main()
{
    int w = 8, h = 12;
    cout << solution(w, h);
    return 0;
}