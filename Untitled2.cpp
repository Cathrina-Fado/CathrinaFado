#include <iostream>

using namespace std;

// Function declarations
void list_files();
void create_directory();
void change_directory();

int main() {
    int choice;
    do {
        cout << "\nDirectory Management System\n";
        cout << "1. List files\n";
        cout << "2. Create directory\n";
        cout << "3. Change directory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list_files();
                break;
            case 2:
                create_directory();
                break;
            case 3:
                change_directory();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
