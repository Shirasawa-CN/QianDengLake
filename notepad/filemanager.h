#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <QString>

class FileManager
{
public:
  FileManager();
private:
  std::vector<std::string> filePathArray;
  unsigned long long filePathArrayPointer;
};

#endif // FILEMANAGER_H
