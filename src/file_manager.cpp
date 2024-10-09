#include <iostream>
#include <filesystem>
#include "file_manager.h"

namespace fs = std::filesystem;

void FileManager::copyFile(const std::string& source, const std::string& destination) {
    fs::copy(source, destination);
    std::cout << "File copied from " << source << " to " << destination << std::endl;
}

void FileManager::moveFile(const std::string& source, const std::string& destination) {
    fs::rename(source, destination);
    std::cout << "File moved from " << source << " to " << destination << std::endl;
}

void FileManager::deleteFile(const std::string& path) {
    fs::remove(path);
    std::cout << "File deleted at " << path << std::endl;
}

int main() {
    std::string operation, source, destination;

    std::cout << "Enter operation (copy/move/delete): ";
    std::cin >> operation;

    if (operation == "copy" || operation == "move") {
        std::cout << "Enter source path: ";
        std::cin >> source;
        std::cout << "Enter destination path: ";
        std::cin >> destination;

        if (operation == "copy") {
            FileManager::copyFile(source, destination);
        } else {
            FileManager::moveFile(source, destination);
        }
    } else if (operation == "delete") {
        std::cout << "Enter file path to delete: ";
        std::cin >> source;
        FileManager::deleteFile(source);
    } else {
        std::cerr << "Invalid operation\n";
        return 1;
    }

    return 0;
}
