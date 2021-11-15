/**
 * Test listDir function.
 */

#include "listdir.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char **argv) {
  string path = "/home/larry";
  string suffix = ".bak";
  vector<string> files, bakFiles;
  listDir(path, files);
  listDir(path, bakFiles, suffix);

  cout << "All files: " << endl;
  for (auto &f : files)
    cout << " |- " << f << endl;

  cout << endl;
  cout << "File names ending in " << suffix << endl;
  for (auto &f : bakFiles)
    cout << " |- " << f << endl;

  return 0;
}
