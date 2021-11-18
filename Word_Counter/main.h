/*
 * @Author: combofish
 * @Date: 2021-11-05 13:42:13
 * @LastEditTime: 2021-11-05 14:17:04
 * @Description: 统计文件中单词个数
 * @Environment: Code::Blocks 16.01 on Win10
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <type_traits>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

const string dataFileName = "test.txt";  /* 读入的文件名*/
const string resultFileName = "res.txt"; /* 保存结果的文件名*/
const int limitedLinesNumber = 64000;    /* 限定文件的行数为 64k */

bool isFileEmpty(std::ifstream &ifs); /* 用于判断打开文件的是否为空文件 */

/* 分割字符串 */
vector<string> &split(const string &str, char delim, vector<string> &elems);

/* 去掉字符串里的标点符号, 保留 `word-word` 或 `word'word` 中的连词符 */
string removePunctuations(const string &s);

/* 读取文件内容到自定义向量中， 并返回文件非空行数。 */
int readFileContent(std::ifstream &ifs, vector<vector<string>> &);

int countWordNumber(
    unordered_map<string, pair<int, int>> &wordInfoList); /* 统计并返回单词个数 */

/* 统计单词信息，并存储到 wordInfo 中 */
void countWord(vector<vector<string>> &,
               unordered_map<string, pair<int, int>> &);

/* 打印 wordInfo 向量，到输出流中，默认到标准输出流 */
void printCountResult(unordered_map<string, pair<int, int>> &,
                      std::ostream &outs = cout);
