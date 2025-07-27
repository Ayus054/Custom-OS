#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TextEditor {
private:
    string filename;
    string content;

public:
    TextEditor(const string& fname) : filename(fname) {}

    void open() {
        ifstream file(filename);
        if (file.is_open()) {
            content.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            file.close();
            cout << "File opened successfully.\n";
        } else {
            cout << "Unable to open file.\n";
        }
    }

    void edit(const string& newContent) {
        content = newContent;
        cout << "Content edited.\n";
    }

    void save() {
        ofstream file(filename);
        if (file.is_open()) {
            file << content;
            file.close();
            cout << "File saved successfully.\n";
        } else {
            cout << "Unable to save file.\n";
        }
    }

    void display() {
        cout << "Content:\n" << content << endl;
    }
};

// Example usage
/*int main() {
    TextEditor editor("example.txt");
    editor.open();
    editor.display();
    editor.edit("New content for the file.");
    editor.save();
    return 0;
}*/