#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Rope.h"

const int LEAF_LEN = 3;

bool IsLeaf(t_rope* rope) {
  return rope->leftChild == NULL && rope->righChild == NULL;
}

int* GetLeafWeights(t_rope* rope, int* currWeight) {
  if (IsLeaf(rope)) {
    return currWeight += rope->weight;
  } else {
    GetLeafWeights(rope->leftChild, currWeight);
    GetLeafWeights(rope->righChild, currWeight);
  }

  return currWeight;
}

void Create(t_rope* node, t_rope* parent, char* string, int leftPointer, int rightPointer) {
  // To create a rope we need to build it from the bottom up, starting with the left most leaf

  t_rope* tempNode = (t_rope*)malloc(sizeof(t_rope));
  tempNode->leftChild = NULL;
  tempNode->righChild = NULL;
  tempNode->parent = parent;

  // Recursive zone
  int stringSize = rightPointer - leftPointer + 1;
  printf("====================================\n");
  printf("The string is %s\n", string);
  printf("The left pointer is %d\n", leftPointer);
  printf("The right pointer is %d\n", rightPointer);
  printf("The string size is %d\n", stringSize);
  if (stringSize > LEAF_LEN)
  {
    tempNode->string = NULL;
    tempNode->weight = (stringSize - 1) / 2;
    node = tempNode;

    
    printf("The weigth for the node is: %i\n", node->weight);
    printf("The substring for the node is: %s\n", node->string);
    printf("====================================\n");
    _sleep(1000);

    int middlePointer = leftPointer + stringSize / 2;
    Create(node->leftChild, node, string, leftPointer, middlePointer);
    Create(node->righChild, node, string, middlePointer + 1, rightPointer);
  } else {
    node = tempNode;
    node->weight = stringSize;
    node->string = malloc(sizeof(char[stringSize]) + 1);
    int stringIndex = 0;
    for (int i = leftPointer; i <= rightPointer; i++) {
      node->string[stringIndex++] = string[i];
    }
    node->string[stringSize] = '\0';

    printf("The weigth for the leaf is: %i\n", node->weight);
    printf("The substring for the leaf is: %s\n", node->string);
    printf("====================================\n");
    _sleep(1000);

    return;
  }
}

char FindCharacter(t_rope* rope, int index) {
  if (IsLeaf(rope)) {
    return rope->string[index];
  } else if (index < rope->weight) {
    FindCharacter(rope->leftChild, index);
  } else if (index > rope->weight) {
    index -= rope->weight;
    FindCharacter(rope->righChild, index);
  }
  
  

}

char** Split(char* string) {

}

void Concatenate(t_rope* resultRope, t_rope* base, t_rope* agg) {
  t_rope* tempRope = (t_rope*)malloc(sizeof(t_rope));
  tempRope->leftChild = base;
  tempRope->righChild = agg;
  int initialWeight = 0;
  GetLeafWeights(base, &initialWeight);
  tempRope->weight = initialWeight;
  resultRope = tempRope;
  
  return;
}

/// @brief Recursively free the in-use memory
/// @param rope 
void Destroy(t_rope* rope) {
  if (rope->leftChild == NULL && rope->righChild == NULL && rope->string == NULL) {
    return;
  }
  
  if (rope->leftChild != NULL) {
    Destroy(rope->leftChild);
  } else if (rope->righChild != NULL) {
    Destroy(rope->righChild);
  }
  
  if (rope->string != NULL) {
    free(rope->string);
  }
  free(rope);
}

char* PrintRope(t_rope* rope) {
  return "ERROR: Not Implemented";
}