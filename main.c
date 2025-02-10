#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 1024

/*
 * For development purposes
 */
#define UNIMPLEMENTED                                                          \
  do {                                                                         \
    fprintf(stderr, "%s() is not implemented yet\n", __func__);                \
    exit(1);                                                                   \
  } while (0)

#define THROWERROR(MSG)          \
  do {                    \
    fprintf(stderr, "%s:%d: ERROR: %s\n", __FILE__, __LINE__, MSG);                \
    exit(1);                                                                   \
  } while(0)

typedef struct {
  char *key;
  size_t value;
  char occupied;
} HashItem;

typedef HashItem HashTable[HASHTABLE_SIZE];

size_t hash(char* key) {
  size_t res = 0;
  size_t i;

  for (i=0; i<strlen(key); i++)
    res += key[i];

  return res;
}

void htInsertItem(HashTable ht, char *key, size_t value) {
  size_t idx = hash(key) % HASHTABLE_SIZE;

  if (ht[idx].occupied == 0) {
    ht[idx].occupied = 1;
    strcpy(ht[idx].key, key);
    ht[idx].value = value;
  } else {
    while (ht[idx].occupied != 0 && idx < HASHTABLE_SIZE)
      idx++;

    if (idx == HASHTABLE_SIZE)
      THROWERROR("Realloc not implemented yet");

    ht[idx].occupied = 1;
    strcpy(ht[idx].key, key);
    ht[idx].value = value;
  }
}

int main() {

  HashTable ht;
  char* hello = "Hello, world!\n";

  printf("%ld\n", hash(hello));

  ht[0].occupied = 'a';
  printf("%d\n", ht[0].occupied);

  return 0;
}
