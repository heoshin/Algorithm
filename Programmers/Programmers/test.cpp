#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

bool Compare(int a, int b)
{
    return a < b;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;

    sort(scoville.begin(), scoville.end(), Compare);

    int i = 0;
    for (; i < scoville.size() && scoville[i] < K; ++i);
    if (i + 1 < scoville.size())
        scoville.erase(scoville.begin() + i + 1, scoville.end());

    list<int> svl(scoville.begin(), scoville.end());

    while (svl.front() < K)
    {
        if (svl.size() < 2) return -1;

        int mixNum = svl.front() + *++svl.begin() * 2;

        svl.pop_front();
        svl.pop_front();

        int mixNumIdx = 0;
        auto it = svl.begin();
        for (; mixNumIdx < svl.size() && *it < mixNum; ++it, ++mixNumIdx);
        svl.insert(it, mixNum);

        answer++;

        for (auto i : svl) printf("%d ", i);
        printf("min: %d ", svl.front());
        printf("mixNum: %d idx: %d\n", mixNum, mixNumIdx);
    }

    return answer;
}

int main()
{
    //printf("result: %d", solution({ 0, 0, 3, 9, 10, 12 }, 7));
    printf("result: %d", solution({ 10, 10, 10, 10, 10 }, 100));

}