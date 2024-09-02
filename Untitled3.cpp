#include <iostream>
#include <direct.h>  // For directory operations
#include <dirent.h>  // For directory listing
#include <cstring>   // For string operations

using namespace std;

void list_files() {
    cout << "1. List all files\n";
    cout << "2. List files based on extension\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    DIR* dir;
    struct dirent* ent;
    string extension;

    switch (choice) {
        case 1:
            if ((dir = opendir(".")) != NULL) {  
                while ((ent = readdir(dir)) != NULL) {  
                    cout << ent->d_name << '\n';
                }
                closedir(dir);
            } else {
                cout << "Could not open directory.\n";
            }
            break;
        case 2:
            cout << "Enter extension (e.g., .txt): ";
            cin >> extension;
            if ((dir = opendir(".")) != NULL) {  
                while ((ent = readdir(dir)) != NULL) {  
                    string filename = ent->d_name;
                    if (filename.size() >= extension.size() &&
                        filename.substr(filename.size() - extension.size()) == extension) {
                        cout << filename << '\n';
                    }
                }
                closedir(dir);
            } else {
                cout << "Could not open directory.\n";
            }
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}

void create_directory() {
    string dirname;
    cout << "Enter directory name: ";
    cin >> dirname;
    if (_mkdir(dirname.c_str()) == 0) {
        cout << "Directory created successfully.\n";
    } else {
        cout << "Failed to create directory. It may already exist.\n";
    }
}

void change_directory() {
    cout << "1. Move to parent directory\n";
    cout << "2. Move to root directory\n";
    cout << "3. Move to a specific directory\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    
    switch (choice) {
        case 1:
            _chdir("..");
            cout << "Moved to parent directory.\n";
            break;
        case 2:
            _chdir("C:\\");  // Root directory for Windows
            cout << "Moved to root directory.\n";
            break;
        case 3: {
            string dirpath;
            cout << "Enter directory path: ";
            cin >> dirpath;
            if (_chdir(dirpath.c_str()) == 0) {
                cout << "Directory changed successfully.\n";
            } else {
                cout << "Directory does not exist.\n";
            }
            break;
        }
        default:
            cout << "Invalid choice.\n";
            break;
    }
}
