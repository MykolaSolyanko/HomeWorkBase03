#include "list_interface.h"

structNode *GetLastEl(const structList &in_oList) {
  constexpr size_t csizeOneElem{1};
  if (bIsEmpty(in_oList)) {
    return nullptr;
  }
  if (Size(in_oList) == csizeOneElem) {
    return in_oList.oFirstNode;
  }
  structNode *oNode{in_oList.oFirstNode};
  while (oNode->oNext != nullptr) {
    oNode = oNode->oNext;
  }
  return oNode;
}

void vPushFront(structList &in_oList, int in_iData) {
  structNode *oNode =
      new (structNode){}; // make "try" for catching allocation troubles
  oNode->iData = in_iData;
  if (bIsEmpty(in_oList)) {
    in_oList.oFirstNode = oNode;
    ++in_oList.sizeSize;
    return;
  }
  oNode->oNext = in_oList.oFirstNode;
  in_oList.oFirstNode->oPrev = oNode;
  in_oList.oFirstNode = oNode;
  ++in_oList.sizeSize;
}

void vPushBack(structList &in_oList, int in_iData) {
  structNode *oNode =
      new (structNode){}; // make "try" for catching allocation troubles
  oNode->iData = in_iData;
  if (bIsEmpty(in_oList)) {
    in_oList.oFirstNode = oNode;
    ++in_oList.sizeSize;
    return;
  }
  structNode *oLastNode{GetLastEl(in_oList)};
  oLastNode->oNext = oNode;
  oNode->oPrev = oLastNode;
  ++in_oList.sizeSize;
}

bool bInsert(structList &in_oList, structNode *oCurrentNode, int in_iData) {
  if (!bCheckNode(in_oList, oCurrentNode)) {
    return false;
  }
  if (oCurrentNode == in_oList.oFirstNode) {
    vPushFront(in_oList, in_iData);
    return true;
  }
  structNode *oNode = new (structNode){}; // make "try"...
  oNode->iData = in_iData;
  oNode->oPrev = oCurrentNode->oPrev;
  oNode->oNext = oCurrentNode;
  (oCurrentNode->oPrev)->oNext = oNode;
  oCurrentNode->oPrev = oNode;
  ++in_oList.sizeSize;
  return true;
}

// Deleting element
bool bPopFront(structList &in_oList) {
  constexpr size_t csizeOneElem{1};

  if (bIsEmpty(in_oList)) {
    return false;
  }
  if (Size(in_oList) == csizeOneElem) {
    delete in_oList.oFirstNode;
    in_oList.oFirstNode = nullptr;
    --in_oList.sizeSize;
    return true;
  }
  structNode *oFirstNode{in_oList.oFirstNode};
  structNode *oNewFirstNode{in_oList.oFirstNode->oNext};
  oNewFirstNode->oPrev = nullptr;
  in_oList.oFirstNode = oNewFirstNode;
  --in_oList.sizeSize;

  delete oFirstNode;
  return true;
}

bool bPopBack(structList &in_oList) {
  constexpr size_t csizeOneElem{1};

  if (bIsEmpty(in_oList)) {
    return false;
  }
  if (Size(in_oList) == csizeOneElem) {
    delete in_oList.oFirstNode;
    in_oList.oFirstNode = nullptr;
    --in_oList.sizeSize;
    return true;
  }
  structNode *oLastNode{GetLastEl(in_oList)};
  structNode *oNewLastNode{oLastNode->oPrev};
  oNewLastNode->oNext = nullptr;
  --in_oList.sizeSize;

  delete oLastNode;
  return true;
}

bool bErase(structList &in_oList, structNode *oCurrentNode) {
  if (!bCheckNode(in_oList, oCurrentNode)) {
    return false;
  }
  if (oCurrentNode == in_oList.oFirstNode) {
    return bPopFront(in_oList);
  }
  if (oCurrentNode == (GetLastEl(in_oList))) {
    return bPopBack(in_oList);
  }

  structNode *oPrevNode{oCurrentNode->oPrev};
  structNode *oNextNode{oCurrentNode->oNext};
  oPrevNode->oNext = oNextNode;
  oNextNode->oPrev = oPrevNode;
  --in_oList.sizeSize;

  delete oCurrentNode;
  return true;
}

void vClear(structList &in_oList) {
  if (bIsEmpty(in_oList)) {
    return;
  }
  structNode *oNode{GetLastEl(in_oList)};
  while (oNode != in_oList.oFirstNode) {
    structNode *oTempNode{oNode};
    oNode = oTempNode->oPrev;
    delete oTempNode;
  }
  delete in_oList.oFirstNode;
  in_oList.oFirstNode = nullptr;
  in_oList.sizeSize = 0;
}

structNode *FindByValue(structList &in_oList, const int in_iValue) {
  structNode *oNode{in_oList.oFirstNode};
  while (oNode->oNext != nullptr) {
    if (bEqual(oNode, in_iValue)) {
      return oNode;
    }
    oNode = oNode->oNext;
  }
  return nullptr;
}

bool bCheckNode(structList &in_oList, structNode *oNodeToCheck) {
  if (bIsEmpty(in_oList)) {
    return false;
  }
  structNode *oNode{in_oList.oFirstNode};
  while (oNode->oNext != nullptr) {
    if (bEqual(oNodeToCheck, oNode)) {
      return true;
    }
    oNode = oNode->oNext;
  }
  return false;
}

void vPrintList(const structList &in_oList) {
  if (bIsEmpty(in_oList)) {
    std::cout << "List is empty\n";
    return;
  }
  structNode *oNode{in_oList.oFirstNode};
  std::cout << "List: ";
  while (oNode->oNext != nullptr) {
    std::cout << oNode->iData << ' ';
    oNode = oNode->oNext;
  }
  std::cout << oNode->iData << " \n";
}
