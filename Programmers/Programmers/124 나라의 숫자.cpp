#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) 
{
    string answer = "";
    int arr[] = { 1, 2, 4 };
    bool bZero = false;
        
    while (true)
    {
        if (n / 4 == 0) {
            answer = to_string(n % 4 - 1) + answer;
            n /= 4;
        }
        else
        {
            answer = to_string(n % 3) + answer;
            n /= 3;
        }
        if (n == 0)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    for (int i = 0; i < 20; ++i)
    {
        cout << i << ": " << solution(i) << "\n";
    }
}