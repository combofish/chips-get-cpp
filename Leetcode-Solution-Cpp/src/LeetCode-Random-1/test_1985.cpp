/**
-- method: str, cmp

--result:
执行用时：160 ms, 在所有 C++ 提交中击败了85.79%的用户
内存消耗：53.8 MB, 在所有 C++ 提交中击败了88.86%的用户
通过测试用例：219 / 219
 */
#include "combofish_utils.hpp"
#include <string>

string kthLargestNumber(vector<string> &nums, int k) {

  std::sort(nums.begin(), nums.end(), [](const string &s1, const string &s2) {
    if (s1.size() == s2.size())
      return s1 > s2;
    else
      return s1.size() > s2.size();
  });

  IC(nums);

  return nums[k - 1];
}

int main() {
  // code start
  // vector<string> nums = {"3", "6", "7", "10"};
  // int k = 4;

  // vector<string> nums = {"623986800", "3",          "887298",     "695",
  //                        "794",       "6888794705", "269409",     "59930972",
  //                        "723091307", "726368",     "8028385786", "378585"};

  // int k = 11;

  vector<string> nums = {"683339452288515879",
                         "7846081062003424420",
                         "4805719838",
                         "4840666580043",
                         "83598933472122816064",
                         "522940572025909479",
                         "615832818268861533",
                         "65439878015",
                         "499305616484085",
                         "97704358112880133",
                         "23861207501102",
                         "919346676",
                         "60618091901581",
                         "5914766072",
                         "426842450882100996",
                         "914353682223943129",
                         "97",
                         "241413975523149135",
                         "8594929955620533",
                         "55257775478129",
                         "528",
                         "5110809",
                         "7930848872563942788",
                         "758",
                         "4",
                         "38272299275037314530",
                         "9567700",
                         "28449892665",
                         "2846386557790827231",
                         "53222591365177739",
                         "703029",
                         "3280920242869904137",
                         "87236929298425799136",
                         "3103886291279"};
  int k = 3;
  IC(nums, k);

  IC(kthLargestNumber(nums, k));
  return 0;
}