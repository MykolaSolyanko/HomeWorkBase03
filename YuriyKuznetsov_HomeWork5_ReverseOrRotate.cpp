// Reverse or rotate
#include <algorithm>
#include <iostream>
#include <string>

void revrot(std::string &inout_sStr, const unsigned int in_cuiPieceSize);

int main() {
  std::string myString{"563000655734469485"};
  std::cout << myString << '\n';
  revrot(myString, 4);
  std::cout << myString << '\n';

  return 0;
}

void revrot(std::string &inout_sStr, const unsigned int in_cuiPieceSize) {
  if (in_cuiPieceSize == 0) {
    inout_sStr.clear();
    return;
  }
  if (in_cuiPieceSize == 1) {
    return;
  }
  if (inout_sStr.length() < in_cuiPieceSize) {
    inout_sStr.clear();
    return;
  }
  size_t szNewLength{(inout_sStr.length() / in_cuiPieceSize) * in_cuiPieceSize};

  inout_sStr.resize(szNewLength);

  for (size_t szCharIndex = 0; szCharIndex <= (szNewLength - in_cuiPieceSize);
       szCharIndex += in_cuiPieceSize) {
    std::string sPieceOfString{inout_sStr, szCharIndex, in_cuiPieceSize};
    unsigned int uiCriterion{};
    for (auto itPieceOfString = sPieceOfString.begin();
         itPieceOfString != sPieceOfString.end(); ++itPieceOfString) {
      if (!std::isdigit(*itPieceOfString)) {
        inout_sStr.clear();
        return;
      }
      std::string sOneChar{*itPieceOfString};
      uiCriterion +=
          std::stoi(sOneChar) * std::stoi(sOneChar) * std::stoi(sOneChar);
    }
    if ((uiCriterion % 2) == 0) {
      std::reverse(sPieceOfString.begin(), sPieceOfString.end());
    } else {
      std::rotate(sPieceOfString.begin(), sPieceOfString.begin() + 1,
                  sPieceOfString.end());
    }
    inout_sStr.replace(szCharIndex, in_cuiPieceSize, sPieceOfString);
  }
}
