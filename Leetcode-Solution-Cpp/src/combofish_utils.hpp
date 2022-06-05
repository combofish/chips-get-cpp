/*
 * @Author: your name
 * @Date: 2022-04-23 19:22:57
 * @LastEditTime: 2022-04-27 18:55:56
 * @LastEditors: your name
 * @Description: utils
 * @FilePath: /use_for_test/combofish_utils.hpp
 */

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <ctime>
#include <functional>
#include <icecream.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::stringstream;
using std::tuple;
using std::unordered_map;
using std::unordered_set;
using std::vector;

typedef vector<vector<vector<int>>> tensor_t;
typedef vector<vector<int>> mat_t;
typedef vector<int> vec_t;

void out_qu(queue<int> qu_) {
  vec_t qu;
  while (!qu_.empty()) {
    qu.emplace_back(qu_.front());
    qu_.pop();
  }

  IC(qu);
}
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 从列表构建链表
ListNode *vec_t2list_node(vec_t &nums) {
  if (nums.empty())
    return nullptr;

  ListNode *head = new ListNode(nums.front());
  ListNode *cur = head;

  for (int i = 1; i < nums.size(); ++i) {
    cur->next = new ListNode(nums[i]);
    cur = cur->next;
  }

  return head;
}

// 输出链表
void out_list_node(ListNode *node, string s = "ListNode") {
  vec_t res;
  while (node != nullptr) {
    res.emplace_back(node->val);
    node = node->next;
  }

  IC(s, res);
}

template <typename T> void out_mat(vector<vector<T>> &mat, string s = "Res") {

  cout << s << endl;
  for (auto line : mat) {
    for (auto n : line) {
      cout << "   " << n;
    }
    cout << endl;
  }

  cout << endl;
}

template <typename T> void out_vec(vector<T> &vec, string s = "Res") {
  cout << s << " :";
  for (auto &c : vec)
    cout << c << ", ";
  cout << endl;
}

// template <typename T> void out(T &t) { cout << t << endl; }
// template <typename T> void outln(T &t) { cout << t; }

template <typename T> void out(T t, string s = "Res") {
  cout << s << ": " << t << " ";
}
template <typename T> void outln(T t, string s = "Res") {
  cout << s << ": " << t << endl;
}

void out_line() { cout << endl; }

void posterOrder(TreeNode *root) {
  if (root != nullptr) {
    cout << root->val << endl;
    posterOrder(root->left);
    posterOrder(root->right);
  }
}

void middleOrder(TreeNode *root) {
  if (root != nullptr) {
    middleOrder(root->left);
    cout << root->val << endl;
    middleOrder(root->right);
  }
}

void hindOrder(TreeNode *root) {
  if (root != nullptr) {
    hindOrder(root->left);
    hindOrder(root->right);
    cout << root->val << endl;
  }
}
