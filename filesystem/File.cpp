#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <cstdio> // for remove()
#include <ctime>
using namespace std;

class File {
private:
    string filename;

public:
    File(const string& fname) : filename(fname) {}

    // Create or update file
    void write(const string& data) {
        ofstream file(filename);
        if (file.is_open()) {
            file << data;
            file.close();
            cout << "File written successfully.\n";
        } else {
            cerr << "Unable to open file for writing.\n";
        }
    }

    // Read file
    string read() const {
        ifstream file(filename);
        if (file.is_open()) {
            string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            file.close();
            return content;
        } else {
            cerr << "Unable to open file for reading.\n";
            return "";
        }
    }

    // Check if file exists
    bool exists() const {
        ifstream file(filename);
        return file.good();
    }

    // Delete file
    bool remove() {
        if (std::remove(filename.c_str()) == 0) {
            cout << "File deleted successfully.\n";
            return true;
        } else {
            cerr << "Unable to delete file.\n";
            return false;
        }
    }

    // Show file metadata
    void showMetadata() const {
        struct stat info;
        if (stat(filename.c_str(), &info) == 0) {
            cout << "Size: " << info.st_size << " bytes\n";
            cout << "Last modified: " << ctime(&info.st_mtime);
            cout << "Created: " << ctime(&info.st_ctime);
        } else {
            cerr << "Unable to get file metadata.\n";
        }
    }
};