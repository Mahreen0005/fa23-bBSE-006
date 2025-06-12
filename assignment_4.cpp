#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int size = right - left + 1;
    int* temp = new int[size];

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int m = 0; m < size; m++) {
        arr[left + m] = temp[m];
    }

    delete[] temp;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int array[] = {45, 12, 89, 3, 7, 32, 18, 90, 25, 66, 1};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    mergeSort(array, 0, size - 1);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
