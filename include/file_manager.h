#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>

class FileManager {
public:
    static void copyFile(const std::string& source, const std::string& destination);
    static void moveFile(const std::string& source, const std::string& destination);
    static void deleteFile(const std::string& path);
};

#endif // FILE_MANAGER_H
