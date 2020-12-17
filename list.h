#include <iostream>

#pragma once

template <class T> struct Node {
  Node *oPrev{};
  T Data{};
  Node *oNext{};

  // operators are overloaded without accounting of floating point types
  bool operator==(const Node &RHNode) { return (Data == RHNode.Data); };
  bool operator==(const T RHValue) { return (Data == RHValue); };
  bool operator<(const Node &RHNode) { return (Data < RHNode.Data); };
  bool operator<(const T RHValue) { return (Data < RHValue); };
};

template <class T> class T_List {
public:
  // iterator functions are not implemented
  T First() const { return oFirstNode->Data; };
  T Last() const;

  void vPushFront(T in_Data);
  void vPushBack(T in_Data);
  bool bInsertBefore(Node<T> *oCurrentNode, T in_Data);
  bool bInsertAfter(Node<T> *oCurrentNode, T in_Data);

  bool bPopFront();
  bool bPopBack();
  bool bErase(Node<T> *oCurrentNode);
  void vClear();

  Node<T> *FindByValue(const T in_Value) const;

  size_t Size() const { return ListSize; };
  bool bIsEmpty() const { return (ListSize == 0); };

  void vPrintList() const;

private:
  Node<T> *oFirstNode{};
  size_t ListSize{};

  bool bCheckNode(Node<T> *oNodeToCheck) const;
  Node<T> *oLastNode() const;
};

template <class T> T T_List<T>::Last() const {
  return oLastNode()->Data; // UB if list is empty
}

template <class T> void T_List<T>::vPushFront(T in_Data) {
  Node<T> *oNode = new Node<T>{}; // make "try" for catching allocation troubles
  oNode->Data = in_Data;
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

template <class T> void T_List<T>::vPushBack(T in_Data) {
  Node<T> *oNode = new Node<T>{}; // make "try" for catching allocation troubles
  oNode->Data = in_Data;
  if (bIsEmpty()) {
    oFirstNode = oNode;
    ++ListSize;
    return;
  }
  Node<T> *oLNode{oLastNode()};
  oLNode->oNext = oNode;
  oNode->oPrev = oLNode;
  ++ListSize;
}

template <class T>
bool T_List<T>::bInsertBefore(Node<T> *oCurrentNode, T in_Data) {
  if (!bCheckNode(oCurrentNode)) {
    return false;
  }
  if (oCurrentNode == oFirstNode) {
    vPushFront(in_Data);
    return true;
  }
  Node<T> *oNode = new Node<T>{}; // make "try"...
  oNode->Data = in_Data;
  oNode->oPrev = oCurrentNode->oPrev;
  oNode->oNext = oCurrentNode;
  (oCurrentNode->oPrev)->oNext = oNode;
  oCurrentNode->oPrev = oNode;
  ++ListSize;
  return true;
}

template <class T>
bool T_List<T>::bInsertAfter(Node<T> *oCurrentNode, T in_Data) {
  if (!bCheckNode(oCurrentNode)) {
    return false;
  }
  if (oCurrentNode == oLastNode()) {
    vPushBack(in_Data);
    return true;
  }
  Node<T> *oNode = new Node<T>{}; // make "try"...
  oNode->Data = in_Data;
  oNode->oPrev = oCurrentNode;
  oNode->oNext = oCurrentNode->oNext;
  (oCurrentNode->oNext)->oPrev = oNode;
  oCurrentNode->oNext = oNode;
  ++ListSize;
  return true;
}

template <class T> bool T_List<T>::bPopFront() {
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
  Node<T> *oCurrentFirstNode{oFirstNode};
  Node<T> *oNewFirstNode{oFirstNode->oNext};
  oNewFirstNode->oPrev = nullptr;
  oFirstNode = oNewFirstNode;
  --ListSize;

  delete oCurrentFirstNode;
  return true;
}

template <class T> bool T_List<T>::bPopBack() {
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
  Node<T> *oLNode{oLastNode()};
  Node<T> *oNewLastNode{oLNode->oPrev};
  oNewLastNode->oNext = nullptr;
  --ListSize;

  delete oLNode;
  return true;
}

template <class T> bool T_List<T>::bErase(Node<T> *oCurrentNode) {
  if (!bCheckNode(oCurrentNode)) {
    return false;
  }
  if (oCurrentNode == oFirstNode) {
    return bPopFront();
  }

  Node<T> *oPrevNode{oCurrentNode->oPrev};
  Node<T> *oNextNode{oCurrentNode->oNext};
  oPrevNode->oNext = oNextNode;
  if (oNextNode != nullptr) {
    oNextNode->oPrev = oPrevNode;
  }
  --ListSize;

  delete oCurrentNode;
  return true;
}

template <class T> void T_List<T>::vClear() {
  if (bIsEmpty()) {
    return;
  }
  Node<T> *oNode{oLastNode()};
  while (oNode != oFirstNode) {
    Node<T> *oTempNode{oNode};
    oNode = oTempNode->oPrev;
    delete oTempNode;
  }
  delete oFirstNode;
  oFirstNode = nullptr;
  ListSize = 0;
}

template <class T> Node<T> *T_List<T>::FindByValue(const T in_Value) const {
  Node<T> *oNode{oFirstNode};
  while (oNode->oNext != nullptr) {
    if (*oNode == in_Value) {
      return oNode;
    }
    oNode = oNode->oNext;
  }
  if (*oNode == in_Value) {
    return oNode;
  }
  return nullptr;
}

template <class T> bool T_List<T>::bCheckNode(Node<T> *oNodeToCheck) const {
  if (bIsEmpty()) {
    return false;
  }
  Node<T> *oNode{oFirstNode};
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

template <class T> void T_List<T>::vPrintList() const {
  if (bIsEmpty()) {
    std::cout << "List is empty\n";
    return;
  }
  Node<T> *oNode{oFirstNode};
  std::cout << "List: ";
  while (oNode->oNext != nullptr) {
    std::cout << oNode->Data << ' ';
    oNode = oNode->oNext;
  }
  std::cout << oNode->Data << " \n";
}

template <class T> Node<T> *T_List<T>::oLastNode() const {
  constexpr size_t csizeOneElem{1};
  if (bIsEmpty()) {
    return nullptr;
  }
  if (ListSize == csizeOneElem) {
    return oFirstNode;
  }
  Node<T> *oNode{oFirstNode};
  while (oNode->oNext != nullptr) {
    oNode = oNode->oNext;
  }
  return oNode;
}
