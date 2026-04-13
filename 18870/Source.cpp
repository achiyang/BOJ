#include <iostream>
#include <vector>
#include <algorithm>

bool firstSort(std::pair<int, int> a, std::pair<int, int> b) {
    return a.first < b.first;
}
bool secondSort(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> myVector;
    for (int i = 0; i < N; i++) {
        int input;
        std::cin >> input;
        myVector.emplace_back(input, i);
    }

    std::sort(myVector.begin(), myVector.end(), firstSort);

    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        if (myVector[i].first != myVector[i + 1].first) {
            myVector[i].first = count++;
        }
        else {
            myVector[i].first = count;
        }
    }
    myVector[N - 1].first = count;

    std::sort(myVector.begin(), myVector.end(), secondSort);

    for (int i = 0; i < N; i++) {
        std::cout << myVector[i].first << ' ';
    }

    return 0;
}