/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <functional>

// void BinaryRecursion(int n, vector<int> &res) {

//   int a;
//   a = n % 2;
//   n = n >> 1;
//   if (n != 0)
//     BinaryRecursion(n, res);
//   res.emplace_back(a);
// }

int main(int argc, char **argv) {
  int n = 22;
  vector<int> res;

  const auto &BinaryRecursion = [](int n, vector<int> &res) {
    std::function<void(int, vector<int> &)> s;
    s = [&](int n, vector<int> &res) {
      int a;
      a = n % 2;
      n = n >> 1;
      if (n != 0)
        s(n, res);
      // BinaryRecursion(n, res);
      res.emplace_back(a);
    };
    s(n, res);
  };

  BinaryRecursion(n, res);

  int result = 0;
  int cur_idx = -1;
  for (int i = 0; i < res.size(); i++) {
    if (res[i] == 1) {
      if (cur_idx != -1) {
        result = std::max(result, i - cur_idx);
      }
      cur_idx = i;
    }
  }


  outln(result, "result");

  out_vec(res);

  return 0;
}
