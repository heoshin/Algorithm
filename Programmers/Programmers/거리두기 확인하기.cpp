#include <string>
#include <vector>

using namespace std;

int findXY[4][2] = { {0, 1}, {0, -1} , {1, 0}, {-1, 0} };

bool isSpace(vector<string> place)
{
    for (int y = 0; y < 5; ++y)
    {
        for (int x = 0; x < 5; ++x)
        {
            char blank = place[y][x];
            if (blank == 'O')
            {
                int cnt = 0;
                for (int k = 0; k < 4; ++k)
                {
                    int findX = x + findXY[k][0];
                    int findY = y + findXY[k][1];
                    if ((findX >= 0 && findX < 5) && (findY >= 0 && findY < 5))
                    {
                        if (place[findY][findX] == 'P') cnt++;
                    }
                    if (cnt >= 2) return false;
                }
            }
            if (blank == 'P')
            {
                int cnt = 0;
                for (int k = 0; k < 4; ++k)
                {
                    int findX = x + findXY[k][0];
                    int findY = y + findXY[k][1];
                    if ((findX >= 0 && findX < 5) && (findY >= 0 && findY < 5))
                    {
                        if (place[findY][findX] == 'P') cnt++;
                    }
                    if (cnt >= 1) return false;
                }
            }
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto place : places)
    {
        answer.push_back(isSpace(place));
    }

    return answer;
}

int main()
{
    vector<vector<string>> places = {{"PPOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    vector<int> result = solution(places);

    for (auto i : result)
    {
        printf("%d ", i);
    }
}