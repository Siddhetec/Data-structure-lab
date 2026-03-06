#include <iostream>
using namespace std;

int arr[50], n;

void create() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
}

void display() {
    cout << "Array elements: ";
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void search() {
    int key, flag = 0;

    cout << "Enter element to search: ";
    cin >> key;

    for(int i=0;i<n;i++) {
        if(arr[i] == key) {
            cout << "Element found at position " << i+1 << endl;
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        cout << "Element not found\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- LINEAR SEARCH MENU ---\n";
        cout << "1. Create Array\n";
        cout << "2. Display\n";
        cout << "3. Search Element\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: cout<<"Exit\n"; break;
            default: cout<<"Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}