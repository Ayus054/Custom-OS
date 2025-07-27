#include <iostream>
#include <vector>
#include <string>
#include <dirent.h> // POSIX directory listing
#include "File.cpp"
using namespace std;

class FileSystem {
public:
    // List files in a directory
    static vector<string> listFiles(const string& path) {
        vector<string> files;
        DIR* dir = opendir(path.c_str());
        if (dir) {
            struct dirent* entry;
            while ((entry = readdir(dir)) != nullptr) {
                // Skip "." and ".."
                if (string(entry->d_name) != "." && string(entry->d_name) != "..") {
                    files.push_back(entry->d_name);
                }
            }
            closedir(dir);
        } else {
            cerr << "Unable to open directory: " << path << endl;
        }
        return files;
    }

    // Create a file
    static void createFile(const string& filename, const string& content) {
        File file(filename);
        file.write(content);
    }

    // Read a file
    static string readFile(const string& filename) {
        File file(filename);
        return file.read();
    }

    // Update a file
    static void updateFile(const string& filename, const string& newContent) {
        File file(filename);
        file.write(newContent);
    }

    // Delete a file
    static void deleteFile(const string& filename) {
        File file(filename);
        file.remove();
    }

    // Show file metadata
    static void showFileMetadata(const string& filename) {
        File file(filename);
        file.showMetadata();
    }
};