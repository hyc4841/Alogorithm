#include <iostream>
#include <vector>

using namespace std;

// 트리 - 예상 대진표 문제
// 대진표는 트리 모양을 하고 있다.
int solution(int n, int a, int b) {

    int round = 0;
    do {
        round++;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        
    } while (a != b);

    return round;
}

int main() {

    int n = 8;
    int a = 4, b = 7;

    cout << solution(n, a, b) << endl;

    return 0;
}