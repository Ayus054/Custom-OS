#include <iostream>
#include "../calculator/Calculator.cpp"
#include "../editor/TextEditor.cpp"
#include "../filesystem/FileSystem.cpp"
#include "../scheduler/Scheduler.cpp"

using namespace std;

class CustomOS {
public:
    void run() {
        int choice;
        do {
            cout << "\n--- Custom OS Menu ---\n";
            cout << "1. Calculator\n";
            cout << "2. Text Editor\n";
            cout << "3. File System\n";
            cout << "4. Scheduler\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    calculatorMenu();
                    break;
                case 2:
                    textEditorMenu();
                    break;
                case 3:
                    fileSystemMenu();
                    break;
                case 4:
                    schedulerMenu();
                    break;
                case 0:
                    cout << "Exiting Custom OS.\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }

private:
    void calculatorMenu() {
        int a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "Add: " << Calculator::add(a, b) << endl;
        cout << "Subtract: " << Calculator::subtract(a, b) << endl;
        cout << "Multiply: " << Calculator::multiply(a, b) << endl;
        cout << "Divide: " << Calculator::divide(a, b) << endl;
    }

    void textEditorMenu() {
        string filename, content;
        cout << "Enter filename: ";
        cin >> filename;
        TextEditor editor(filename);
        editor.open();
        editor.display();
        cout << "Enter new content: ";
        cin.ignore();
        getline(cin, content);
        editor.edit(content);
        editor.save();
    }

    void fileSystemMenu() {
        int fsChoice;
        do {
            cout << "\n--- File System Menu ---\n";
            cout << "1. List files in directory\n";
            cout << "2. Create file\n";
            cout << "3. Read file\n";
            cout << "4. Update file\n";
            cout << "5. Delete file\n";
            cout << "6. Show file metadata\n";
            cout << "0. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> fsChoice;
            string path, filename, content;
            switch (fsChoice) {
                case 1:
                    cout << "Enter directory path to list files: ";
                    cin >> path;
                    {
                        auto files = FileSystem::listFiles(path);
                        cout << "Files:\n";
                        for (const auto& f : files) {
                            cout << f << endl;
                        }
                    }
                    break;
                case 2:
                    cout << "Enter filename to create: ";
                    cin >> filename;
                    cout << "Enter content: ";
                    cin.ignore();
                    getline(cin, content);
                    FileSystem::createFile(filename, content);
                    break;
                case 3:
                    cout << "Enter filename to read: ";
                    cin >> filename;
                    cout << "Content:\n" << FileSystem::readFile(filename) << endl;
                    break;
                case 4:
                    cout << "Enter filename to update: ";
                    cin >> filename;
                    cout << "Enter new content: ";
                    cin.ignore();
                    getline(cin, content);
                    FileSystem::updateFile(filename, content);
                    break;
                case 5:
                    cout << "Enter filename to delete: ";
                    cin >> filename;
                    FileSystem::deleteFile(filename);
                    break;
                case 6:
                    cout << "Enter filename to show metadata: ";
                    cin >> filename;
                    FileSystem::showFileMetadata(filename);
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (fsChoice != 0);
    }

    void schedulerMenu() {
        Scheduler scheduler;
        int schChoice;
        do {
            cout << "\n--- Scheduler Menu ---\n";
            cout << "1. Add Process\n";
            cout << "2. List Processes\n";
            cout << "3. Run Scheduler\n";
            cout << "0. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> schChoice;
            switch (schChoice) {
                case 1: {
                    string name;
                    int burstTime;
                    cout << "Enter process name: ";
                    cin >> name;
                    cout << "Enter burst time: ";
                    cin >> burstTime;
                    scheduler.addProcess(name, burstTime);
                    break;
                }
                case 2:
                    scheduler.listProcesses();
                    break;
                case 3:
                    scheduler.run();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (schChoice != 0);
    }
};

int main() {
    CustomOS os;
    os.run();
    return 0;
}