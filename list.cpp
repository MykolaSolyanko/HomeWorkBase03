#include "list.h"

int C_List::Last() {
  return oLastNode()->iData; // UB if list is empty
}

void C_List::vPushFront(int in_iData) {
  Node *oNode = new Node{}; // make "try" for catching allocation troubles
  oNode->iData = in_iData;
  if (bIsEmpty()) {
    oFirstNode = oNode;
    ++ListSize;
    return;
  }
  oNode->oNext = oFirstNode;
  oFirstNode->oPrev = oNode;
  oFirstNode = oNode;
  ++ListSize;
}

void C_List::vPushBack(int in_iData) {
  Node *oNode = new Node{}; // make "try" for catching allocation troubles
  oNode->iData = in_iData;
  if (bIsEmpty()) {
    oFirstNode = oNode;
    ++ListSize;
    return;
  }
  Node *oLNode{oLastNode()};
  oLNode->oNext = oNode;
  oNode->oPrev = oLNode;
  ++ListSize;
}

bool C_List::bInsertBefore(Node *oCurrentNode, int in_iData) {
  if (!bCheckNode(oCurrentNode)) {
    return false;
  }
  if (oCurrentNode == oFirstNode) {
    vPushFront(in_iData);
    return true;
  }
  Node *oNode = new Node{}; // make "try"...
  oNode->iData = in_iData;
  oNode->oPrev = oCurrentNode->oPrev;
  oNode->oNext = oCurrentNode;
  (oCurrentNode->oPrev)->oNext = oNode;
  oCurrentNode->oPrev = oNode;
  ++ListSize;
  return true;
}

bool C_List::bInsertAfter(Node *oCurrentNode, int in_iData) {
  if (!bCheckNode(oCurrentNode)) {
    return false;
  }
  if (oCurrentNode == oLastNode()) {
    vPushBack(in_iData);
    return true;
  }
  Node *oNode = new Node{}; // make "try"...
  oNode->iData = in_iData;
  oNode->oPrev = oCurrentNode;
  oNode->oNext = oCurrentNode->oNext;
  (oCurrentNode->oNext)->oPrev = oNode;
  oCurrentNode->oNext = oNode;
  ++ListSize;
  return true;
}

bool C_List::bPopFront() {
  constexpr size_t csizeOneElem{1};

  if (bIsEmpty()) {
    return false;
  }
  if (ListSize == csizeOneElem) {
    delete oFirstNode;
    oFirstNode = nullptr;
    --ListSize;
    return true;
  }
  Node *oCurrentFirstNode{oFirstNode};
  Node *oNewFirstNode{oFirstNode->oNext};
  oNewFirstNode->oPrev = nullptr;
  oFirstNode = oNewFirstNode;
  --ListSize;

  delete oCurrentFirstNode;
  return true;
}

bool C_List::bPopBack() {
  constexpr size_t csizeOneElem{1};

  if (bIsEmpty()) {
    return false;
  }
  if (ListSize == csizeOneElem) {
    delete oFirstNode;
    oFirstNode = nullptr;
    --ListSize;
    return true;
  }
  Node *oLNode{oLastNode()};
  Node *oNewLastNode{oLNode->oPrev};
  oNewLastNode->oNext = nullptr;
  --ListSize;

  delete oLNode;
  return true;
}

bool C_List::bErase(Node *oCurrentNode) {
  if (!bCheckNode(oCurrentNode)) {
    return false;
  }
  if (oCurrentNode == oFirstNode) {
    return bPopFront();
  }
  if (oCurrentNode == oLastNode()) {
    return bPopBack();
  }

  Node *oPrevNode{oCurrentNode->oPrev};
  Node *oNextNode{oCurrentNode->oNext};
  oPrevNode->oNext = oNextNode;
  oNextNode->oPrev = oPrevNode;
  --ListSize;

  delete oCurrentNode;
  return true;
}

void C_List::vClear() {
  if (bIsEmpty()) {
    return;
  }
  Node *oNode{oLastNode()};
  while (oNode != oFirstNode) {
    Node *oTempNode{oNode};
    oNode = oTempNode->oPrev;
    delete oTempNode;
  }
  delete oFirstNode;
  oFirstNode = nullptr;
  ListSize = 0;
}

Node *C_List::FindByValue(const int in_iValue) {
  Node *oNode{oFirstNode};
  while (oNode->oNext != nullptr) {
    if (*oNode == in_iValue) {
      return oNode;
    }
    oNode = oNode->oNext;
  }
  if (*oNode == in_iValue) {
    return oNode;
  }
  return nullptr;
}

bool C_List::bCheckNode(Node *oNodeToCheck) {
  if (bIsEmpty()) {
    return false;
  }
  Node *oNode{oFirstNode};
  while (oNode->oNext != nullptr) {
    if (*oNodeToCheck == *oNode) {
      return true;
    }
    oNode = oNode->oNext;
  }
  if (*oNodeToCheck == *oNode) {
    return true;
  }
  return false;
}

void C_List::vPrintList() {
  if (bIsEmpty()) {
    std::cout << "List is empty\n";
    return;
  }
  Node *oNode{oFirstNode};
  std::cout << "List: ";
  while (oNode->oNext != nullptr) {
    std::cout << oNode->iData << ' ';
    oNode = oNode->oNext;
  }
  std::cout << oNode->iData << " \n";
}

Node *C_List::oLastNode() {
  constexpr size_t csizeOneElem{1};
  if (bIsEmpty()) {
    return nullptr;
  }
  if (ListSize == csizeOneElem) {
    return oFirstNode;
  }
  Node *oNode{oFirstNode};
  while (oNode->oNext != nullptr) {
    oNode = oNode->oNext;
  }
  return oNode;
}
