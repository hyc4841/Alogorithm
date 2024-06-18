#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

bool solution(vector<string> phoneBook) {
// substr() : 문자열에 적용해서 하위 문자열로 변환하는 함수
// substr(시작 인덱스, 몇개 추출), substr(시작 인덱스) : 시작 인덱스부터 끝까지 추출
// substr
    sort(phoneBook.begin(), phoneBook.end()); // sort함수 이용해서 벡터 정렬하기

    for (int i = 0; i < phoneBook.size() - 1; i++) {
        if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size())) { // 접두사가 있으면 false 
            return false;   
        }
    }
    
    // 접두사가 없으면 true
    return true;
}

int main() {

    vector<string> phoneBook = {"119", "97674223", "1195524421"};

    cout << solution(phoneBook) << endl;


    return 0;
}