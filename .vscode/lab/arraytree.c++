#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

int root(int key, int arr[]) {
    if (arr[0] != 0) {
        cout << "Root is already present in the tree" << endl;
    } else {
        arr[0] = key;
        return 0;
    }
}

int set_left(int key, int parent, int arr[]) {
    if (arr[parent] == 0) {
        cout << "Can't set child at " << (parent * 2) + 1 << endl;
        return -1;
    } else {
        arr[(parent * 2) + 1] = key;
        return 0;
    }
}

int set_right(int key, int parent, int arr[]) {
    if (arr[parent] == 0) {
        cout << "Can't set parent at " << (parent * 2) + 2 << endl;
        return -1;
    } else {
        arr[(parent * 2) + 2] = key;
        return 0;
    }
}

int print_tree(int arr[]) {
    int last_non_zero = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (arr[i] != 0) {
            last_non_zero = i;
        }
    }
    for (int i = 0; i <= last_non_zero; i++) {
        if (arr[i] != 0) {
            cout << arr[i] <<" ";
        } else {
            cout << "-";
        }
    }
    cout << endl;
}

int main() {
    int arr[MAX_SIZE] = {0};
    int choice, key, parent;
    while (true) {
        cout << "1. Add root" << endl;
        cout << "2. Add left child" << endl;
        cout << "3. Add right child" << endl;
        cout << "4. Print tree" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                root(key, arr);
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter parent index: ";
                cin >> parent;
                set_left(key, parent, arr);
                break;
            case 3:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter parent index: ";
                cin >> parent;
                set_right(key, parent, arr);
                break;
            case 4:
                print_tree(arr);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
}