#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void organize_files(const std::string& path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::string ext = entry.path().extension().string();
            fs::create_directory(path + "/" + ext);
            fs::rename(entry.path(), path + "/" + ext + "/" + entry.path().filename().string());
        }
    }
    std::cout << "Files organized by type in " << path << std::endl;
}

int main() {
    std::string path;
    std::cout << "Enter the directory path to organize: ";
    std::cin >> path;
    organize_files(path);
    return 0;
}
