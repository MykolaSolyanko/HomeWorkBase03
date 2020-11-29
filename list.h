#pragma once

#include <iostream>

struct Node {
  Node *oPrev{};
  int iData{};
  Node *oNext{};

  bool operator==(const Node &RHNode) { return (iData == RHNode.iData); };
  bool operator==(const int iRHValue) { return (iData == iRHValue); };
  bool operator<(const Node &RHNode) { return (iData < RHNode.iData); };
  bool operator<(const int iRHValue) { return (iData < iRHValue); };
};

class C_List {
public:
  // iterator functions are not implemented
  int First() { return oFirstNode->iData; };
  int Last();

  void vPushFront(int in_iData);
  void vPushBack(int in_iData);
  bool bInsertBefore(Node *oCurrentNode, int in_iData);
  bool bInsertAfter(Node *oCurrentNode, int in_iData);

  bool bPopFront();
  bool bPopBack();
  bool bErase(Node *oCurrentNode);
  void vClear();

  Node *FindByValue(const int in_iValue);

  size_t Size() { return ListSize; };
  bool bIsEmpty() { return (ListSize == 0); };

  void vPrintList();

private:
  Node *oFirstNode{};
  size_t ListSize{};

  bool bCheckNode(Node *oNodeToCheck);
  Node *oLastNode();
};
