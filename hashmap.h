#ifndef HASHMAP_C
#define HASHMAP_C

enum HashReturnCode {}

typedef void* Generic;

typedef struct hashmap {
  int num_of_entries;

} HashMap;

typedef struct hashelement {
  int key;
  int in_use;
  Generic data;
} HashElement;


// --------------------------------------------------------------------- //
// Helper Functions
int hash_function();
// --------------------------------------------------------------------- //


// --------------------------------------------------------------------- //
// Mutating functions
//
// 	 Removes an element by key from the input map.
HashReturnCode remove_hashelement(HashMap input_map, int key);
// --------------------------------------------------------------------- //

// Returns a new hashmap
// Assummptions:
HashMap new_hashmap();

// --------------------------------------------------------------------- //
// Iterates over the hashmap, and "prints"
HashReturnCode iterate_hashmap(HashMap input_map);
// --------------------------------------------------------------------- //
#endif
