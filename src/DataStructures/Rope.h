/// <summary>
/// This header declares the necessary operations and data for the rope data structure
/// A rope is a special type of data structure where a string is split and stored in the leaves
/// </summary>

#pragma once

typedef struct Rope {
  int weight;
  char* string;       // The string will only be populated in the leaf nodes
  struct Rope* parent;
  struct Rope* leftChild;
  struct Rope* rightChild;
} t_rope;

void Create(t_rope** node, t_rope* parent, char* string, int leftPointer, int rightPointer);

char FindCharacter(t_rope* rope, int index);

char** Split(char* string);

void Concatenate(t_rope* resultRope, t_rope* rope1, t_rope* rope2);

void Destroy(t_rope** rope);

char* PrintRope(t_rope* rope);
