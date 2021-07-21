#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool Compare(int a, int b)
{
    return a < b;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K)
    {
        printf("top: %d ", pq.top());

        if (pq.size() < 2) return -1;
        int lower1 = pq.top();
        pq.pop();
        int lower2 = pq.top();
        pq.pop();

        pq.push(lower1 + lower2 * 2);

        answer++;
    }

    return answer;
}

int main()
{
    //printf("result: %d", solution({ 0, 0, 3, 9, 10, 12 }, 7));
    printf("result: %d", solution({ 10, 10, 10, 10, 10 }, 100));

}