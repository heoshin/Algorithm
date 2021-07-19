#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    array<array<int, 2>, 2> HandPos = { 0, 3, 2, 3 };
    
    //왼손: 0  오른손: 1
    int Dir = hand == "left" ? 0 : 1;
    for (auto& number : numbers) {
        //현재 키패드 번호를 좌표로 변환
        number = number == 0 ? 11 : number;
        array<int, 2> curPos = { (number - 1) % 3, (number - 1) / 3 };
        //왼쪽 열: 왼손
        if (curPos[0] == 0) {
            HandPos[0] = curPos;
            answer += "L";
            continue;
        }
        //오른쪽 열: 오른손
        else if (curPos[0] == 2) {
            HandPos[1] = curPos;
            answer += "R";
            continue;
        }
        //현재 키패드 위치와 양손 거리 계산
        array<int, 2> dis = { abs(HandPos[0][0] - curPos[0]) + abs(HandPos[0][1] - curPos[1]),
                     abs(HandPos[1][0] - curPos[0]) + abs(HandPos[1][1] - curPos[1]) };
        //printf("%d: %d, %d    L: %d, %d  %d  R: %d, %d  %d\n", number, curPos[0], curPos[1], HandPos[0][0], HandPos[0][1], dis[0], HandPos[1][0], HandPos[1][1], dis[1]);
        //양손 거리 같을 때
        if (dis[0] == dis[1]) {
            HandPos[Dir] = curPos;
            answer += Dir ? "R" : "L";
        }
        //왼손이 가까울 때
        else if (dis[0] < dis[1]) {
            HandPos[0] = curPos;
            answer += "L";
        }
        //오른손이 가까울 때
        else {
            HandPos[1] = curPos;
            answer += "R";
        }
    }

    return answer;
}

int main() {
    vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
    string hand = "left";

    string result = solution(numbers, hand);

    cout << result;
}