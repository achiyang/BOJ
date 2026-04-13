#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    int age;
    char* name;
} Person;

void merge(Person** arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열 생성
    Person** L = (Person**)malloc(sizeof(Person*) * n1);
    Person** R = (Person**)malloc(sizeof(Person*) * n2);

    // 왼쪽과 오른쪽 배열로 복사
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 병합 과정
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i]->age <= R[j]->age) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남아있는 원소들 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 임시 배열 해제
    free(L);
    free(R);
}

void mergeSort(Person** arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 왼쪽과 오른쪽 부분 배열을 정렬
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 정렬된 부분 배열들을 병합
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    Person* people[100000];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char input[101];
        people[i] = (Person*)malloc(sizeof(Person));
        scanf(" %d %s", &people[i]->age, input);
        people[i]->name = (char*)malloc(strlen(input) + 1);
        strcpy(people[i]->name, input);
    }

    // 병합 정렬 호출
    mergeSort(people, 0, N - 1);

    // 정렬된 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", people[i]->age, people[i]->name);
    }

    // 동적 할당 해제
    for (int i = 0; i < N; i++) {
        free(people[i]->name);
        free(people[i]);
    }

    return 0;
}