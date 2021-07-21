#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int loc = 1;

    deque<int> d(priorities.begin(), priorities.end());

    for (; !d.empty(); d.pop_front()) 
    {
        if (d.front() <= *max_element(d.begin() + loc, d.end()))
        {
            d.push_back(d.front());
            printf("push ");
        }
        else
        {
            if (location)
            ++answer;
        }

        for (const auto& i : d) printf("%d ", i);
        printf("max: %d\n", *max_element(d.begin() + loc, d.end()));
    }

    max_element(d.begin(), d.end());


    return answer;
}

int main()
{
    printf("res: %d\n", solution({ 4, 1, 3, 2 }, 2));
    printf("res: %d\n", solution({ 1, 1, 9, 1, 1, 1 }, 0));

    return 0;
}