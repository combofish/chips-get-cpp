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
#include <sstream>
#include <type_traits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * @description: 定义结构体用于保存单词，
 * 及其在文本中首次出现行号、出现次数（区分大小写）
 */
struct WordInfo {
  string word;
  int lineNumberOfFirstOccurrence;
  int count;
};

const string dataFileName = "test.txt";  /* 读入的文件名*/
const string resultFileName = "res.txt"; /* 保存结果的文件名*/
const int limitedLinesNumber = 64000;    /* 限定文件的行数为 64k */

/* 读取文件内容到自定义向量中， 并返回文件非空行数。 */
int readFileContent(std::ifstream &ifs, vector<vector<string>> &);

int countWordNumber(vector<vector<string>> &); /* 统计并返回单词个数 */
bool isFileEmpty(std::ifstream &ifs); /* 用于判断打开文件的是否为空文件 */

/* 去掉字符串里的标点符号, 保留 `word-word` 中的连词符 */
string removePunctuations(const string &s);

/* 分割字符串 */
vector<string> &split(const string &str, char delim, vector<string> &elems);

/* 统计单词信息，并存储到 wordInfo 向量中 */
void countAll(vector<vector<string>> &, vector<WordInfo> &);

/* 记录单词信息，所在行号到 wordInfo 向量中 */
void recordWord(const string &word, int lineNumber,
                vector<WordInfo> &wordInfoList);

/**
 * @description:  输入单词和 wordInfo 向量，判断某个单词是否已被记录：
 *     若是：返回该单词在 wordInfo 向量中的索引
 *     若否：该单词还没被记录，返回 -1
 */
int isExist(const string &word, vector<WordInfo> &wordInfoList);

/**
 * @description: 打印 wordInfo 向量，到输出流中，默认到标准输出流
 */
void printCountResult(vector<WordInfo> &wordInfoList,
                      std::ostream &outs = cout);
