#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

long long polunomial_hash(const string& str) { // 문자열 해싱(다항 해싱) 방법 코드로 그대로 구현. 그런데 이 코드는 p를 역방향으로 적용함.
    const int p = 31;
    const long long m = 1000000007;
    long long hash_value = 0;

    /*
    for (char c : str) { // 역방향 다항 해싱
        hash_value = (hash_value * p + c) % m;
    }
    */
    
    int pp = 1;
    for (char c : str) { // 내가 만든 정방향 다항 해싱
        hash_value = hash_value + (c * pp) % m;
        pp *= p;
    }

    return hash_value;
}


vector<bool> solution(vector<string> string_list, vector<string> query_list) {
    unordered_set<long long> hash_set;

    for (const string& str : string_list) { // 왜 참조 값으로 갖다 쓰지? 
        long long hash = polunomial_hash(str);
        hash_set.insert(hash); // 문자열 해싱 함수 돌린후 나온 값을 set에 넣어준다.
    }    

    vector<bool> result;

    for (const string& query : query_list) {
        long long query_hash = polunomial_hash(query); // query_list쪽도 해싱 함수 돌려서 바꿔줌
        bool found = (hash_set.find(query_hash) != hash_set.end()); // find()에서 끝까지 찾지 못하면 end()의 값을 반화하기 때문에 end()와 비교하는 것임.
        result.push_back(found);
    }

    return result;
}

int main() {

    vector<string> string_list = {"apple", "banana", "cherry"};
    vector<string> query_list = {"banana", "kiwi", "melon", "apple"};

    vector<bool> answer = solution(string_list, query_list);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}