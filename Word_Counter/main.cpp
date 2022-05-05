/*
 * @Author: combofish
 * @Date: 2021-11-05 13:42:13
 * @LastEditTime: 2021-11-05 14:17:04
 * @Description: 统计文件中单词个数
 * @Environment: Code::Blocks 16.01 on Win10
 */

#include "main.h"
#include <cctype>
#include <string.h>
#include <string>
#include <unordered_map>
#include <utility>

/**
 * @description: 主函数
 */
int main(int argc, char **argv) {

  std::ifstream ifs(dataFileName);
  std::ofstream ofs(resultFileName);

  int linesNumber; /* 用于保存文件行数 */
  int wordsNumber; /* 用于保存单词个数 */

  /* 用于保存每个单词的统计信息: 单词，首次出现行号，出现次数 */
  unordered_map<string, pair<int, int>> wordInfoList;

  std::stringstream resultStringStream; /* 用字符流保存要输出的数据 */
  vector<vector<string>> sta; /* 初始化默认栈，初始大小为16 */

  if (!ifs.is_open()) /* 检查文件是否存在 */
  {
    cout << "Open file failed, make sure file existed!" << endl;
    return -1;
  }

  if (isFileEmpty(ifs)) /* 判断是否为空文件*/
  {
    cout << "File is blank!" << endl;
    return -1;
  }

  linesNumber = readFileContent(ifs, sta); /* 读取文件，并返回读取文件的行数 */
  countWord(sta, wordInfoList);                /* 统计单词详情 */
  wordsNumber = countWordNumber(wordInfoList); /* 统计单词个数 */

  if (linesNumber >
      limitedLinesNumber) /* 当文件行数过多时（大于 64k），给出提示 */
  {
    cout << "File is too big. The lines number is : " << linesNumber
         << " more then 64k!" << endl;
  }

  resultStringStream << "Read file:\t\t" << dataFileName << endl;
  resultStringStream << "Lines number:\t\t" << linesNumber << endl;
  resultStringStream << "Words number:\t\t" << wordsNumber << endl;

  cout << resultStringStream.str();
  printCountResult(wordInfoList); /* 把统计结果打印的标准输出流（默认）*/

  ofs << resultStringStream.str();
  printCountResult(wordInfoList, ofs); /* 把统计结果打印到文件输出流 */

  ifs.close(); /* 关闭输入文件 */
  ofs.close(); /* 关闭输出文件 */
  return 0;
}

/**
 * @description: 打印 wordInfo，到输出流中，默认到标准输出流
 * @param {vector<WordInfo>} &wordInfoList
 * @param {ostream} &outs
 * @return {void}
 */
void printCountResult(unordered_map<string, pair<int, int>> &wordInfoList,
                      std::ostream &outs) {

  outs << "Unique word number:\t" << wordInfoList.size() << endl;
  outs << "Word"
       << "\t\t"
       << "First appear in"
       << "\t\t"
       << "Count" << endl;

  for (auto &wordInfo : wordInfoList) {
    outs << wordInfo.first << "\t\t" << wordInfo.second.first << "\t\t\t"
         << wordInfo.second.second << endl;
  }
}

/**
 * @description: 统计单词信息，并存储到 wordInfo 向量中
 * @param {vector<vector<string>> &sta, vector<WordInfo>} &wordInfoList
 * @return {void}
 */
void countWord(vector<vector<string>> &sta,
               unordered_map<string, pair<int, int>> &wordInfoList) {
  int lineNumber = 0;
  for (auto lineStr : sta) {
    ++lineNumber;
    for (auto str : lineStr) {
      if (!str.empty()) {
        auto it = wordInfoList.find(str);
        if (it != wordInfoList.end())
          wordInfoList[str].second++;
        else
          wordInfoList[str] = std::make_pair(lineNumber, 1);
      }
    }
  }
}

/**
 * @description: 统计单词个数
 * @param {vector<vector<string>>} &sta
 * @return {int}
 */
int countWordNumber(unordered_map<string, pair<int, int>> &wordInfoList) {
  int wordsNumber = 0;
  for (auto wordInfo : wordInfoList)
    wordsNumber += wordInfo.second.second;
  return wordsNumber;
}

/**
 * @description: 读取文件内容到自定义模板栈中，并返回读取文件的行数（包括空行）
 * @param {ifstream} &ifs
 * @param {vector<vector<string>>} &
 * @return {int}
 */
int readFileContent(std::ifstream &ifs, vector<vector<string>> &sta) {
  int linesNumber = 0;
  string lineStr;
  bool thisLineNotEnd = false;
  bool preLineNotEnd = false;

  while (ifs) {
    vector<string> vstr;
    string tmpStr;
    std::getline(ifs, lineStr);
    if (-1 == ifs.tellg())
      break;

    // cout << ">>> Read Line: " << lineStr << " tellg: " << ifs.tellg() <<
    // endl;

    char end_char = lineStr.empty() ? ' ' : lineStr[lineStr.size() - 1];
    if (end_char == '-') {
      thisLineNotEnd = true;
    }
    tmpStr = removePunctuations(lineStr);
    split(tmpStr, ' ', vstr);
    if (!vstr.empty() && preLineNotEnd == true) {
      // cout << "linesNumber: " << linesNumber << endl;

      vector<string> *preLine = &sta[sta.size() - 1];
      *(preLine->rbegin()) += *vstr.begin();
      vstr.erase(vstr.begin());
    }
    preLineNotEnd = thisLineNotEnd;
    thisLineNotEnd = false;

    sta.push_back(vstr);
    linesNumber++;
  }

  // cout << "sta.size(): " << sta.size() << endl;
  return linesNumber;
}

/**
 * @description: 用于判断打开的是否为空文件
 * @param {ifstream} &ifs
 * @return {*}
 */
bool isFileEmpty(std::ifstream &ifs) {
  if (ifs.peek() == std::ifstream::traits_type::eof())
    return true;

  return false;
}

/**
 * @description: 去掉标点符号, 保留 `word-word` 中的连词符
 * @param {string} &s
 * @return {*}
 */
string removePunctuations(const string &s) {
  string tmp = "";
  for (int i = 0; i < s.size(); i++) {
    // 循环 string.
    if ((i != 0) && (i != s.size() - 1) && (!std::ispunct(s[i - 1])) &&
        ((s[i] == '-') || (s[i] == '\'')) && (!std::ispunct(s[i + 1]))) {
      tmp += s[i];
    }

    if (!std::ispunct(s[i]))
      tmp += s[i];
  }
  return tmp;
}

/**
 * @description: 分割字符串
 * @param {string} &str
 * @param {char} delim
 * @param {vector<string>} &elems
 * @return {*}
 */
vector<string> &split(const string &str, char delim, vector<string> &elems) {
  std::stringstream ss(str);
  string item;
  while (std::getline(ss, item, delim))
    elems.push_back(item);

  return elems;
}
