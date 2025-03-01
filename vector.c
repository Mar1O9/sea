// Copyright 2025 Mahmoud Abdelrahman <mahmud.yousif.04@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef VECTOR_C_
#define VECTOR_C_
#define VECTOR_ERROR_VAL 00
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  // TODO: replace the int32_t with the type you need
  int32_t *data;
  size_t length;
  size_t capacity;
} Vector;


#define _vectorCheckSize(vector) do \
{ \
    if (vector.length >= vector.capacity) { \
      if (vector.capacity == 0) \
      vector.capacity = 2;\
    else\
      vector.capacity *= 2; \
    vector.data = realloc(vector.data, vector.capacity * sizeof(vector.data[0])); \
  } \
}while(0)

#define VectorAppend(vector,  value) do \
{                                       \
    _vectorCheckSize(vector);\
  vector.data[vector.length++] = value; \
} while (0)

#define VectorPop(vector) do \
{ \
  assert(vector.length > 0 && "Vector should be > 0 to pop"); \
  vector.data[vector.length] = 0; \
  vector.length--; \
} while(0)


#define  VectorShift(vector) do \
{ \
  assert(vector.length > 0 && "Vector should be > 0 to shift"); \
  memmove(&vector.data[0], &vector.data[1], \
      vector.capacity * sizeof(*vector.data)); \
  vector.length--; \
} while(0)


#define  VectorUnShift(vector, value) do \
{ \
  _vectorCheckSize(vector);\
  memmove(&vector.data[1], &vector.data[0], \
         vector.capacity * sizeof(*vector.data)); \
  vector.data[0] = value; \
  vector.length++; \
} while(0)


#define  VectorInsert(vector, index, value) do \
{ \
   _vectorCheckSize(vector);\
  memmove(&vector.data[index + 1], &vector.data[index], \
          vector.capacity * sizeof(*vector.data)); \
  vector.data[index] = value; \
  vector.length++;\
} while(0)


// TODO: replace the type of from int32_t to the type you need
// int32_t VectorGetElement(Vector *vector, int index) {
//   if (index > vector->length) {
//     return VECTOR_ERROR_VAL;
//   }
//   return vector->data[index];
// }

#endif // VECTOR_C_
