#pragma once

#include <iostream>

struct structNode{
  structNode* oPrev{};
  int iData;
  structNode* oNext{};
};

struct structList{
  structNode* oFirstNode{};
  size_t sizeSize{};
};

//Element access
inline structNode* GetFirstEl(const structList& in_oList) {return in_oList.oFirstNode;};
structNode* GetLastEl(const structList& in_oList);

// Inserting element
void vPushFront(structList& in_oList, int in_iData);
void vPushBack(structList& in_oList, int in_iData);
bool bInsert(structList& in_oList, structNode* oCurrentNode, int in_iData);

// Deleting element
bool bPopFront(structList& in_oList);
bool bPopBack(structList& in_oList);
bool bErase(structList& in_oList, structNode* oCurrentNode);
void vClear(structList& in_oList);

// Compare
inline bool bCmp(structNode* oLess, structNode* oMore) {return (oLess->iData < oMore->iData);}
inline bool bEqual(structNode* oFirst, structNode* oSecond) {return (oFirst->iData == oSecond->iData);}
inline bool bEqual(structNode* oFirst, int iSecond) {return (oFirst->iData == iSecond);}

// Find element
structNode* FindByValue(structList& in_oList, const int in_iValue);

// Capacity
inline size_t Size(const structList& in_oList) {return in_oList.sizeSize;};
inline bool bIsEmpty(const structList& in_oList) {return (in_oList.sizeSize == 0);};

// Helpers
bool bCheckNode(structList& in_oList, structNode* oNodeToCheck);
void vPrintList(const structList& in_oList);
