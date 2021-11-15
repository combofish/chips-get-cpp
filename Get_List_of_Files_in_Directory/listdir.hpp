#include <filesystem>
#include <string>
#include <vector>

/**
 * @description: 获取目录下的文件，可选获取目录下以 suffix 结尾的文件
 * @param {const string} &path
 * @param {vector<string>} &files
 * @param {string} &suffix
 * @return {void}
 */
void listDir(const std::string &path, std::vector<std::string> &files,
             std::string suffix = "") {

  for (auto &entry : std::filesystem::directory_iterator(path)) {
    std::string fileName = entry.path();

    if (suffix.empty()) {
      files.push_back(fileName);
    } else {
      int pos = fileName.rfind(suffix);
      if (pos != std::string::npos &&
          fileName.compare(pos, suffix.size() - 1, suffix)) {
        files.push_back(fileName);
      }
    }
  }
}
