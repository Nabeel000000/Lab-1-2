## 🔎 Featured Implementation: Custom String ADT (`06_string`)
This directory contains a custom **Dynamic String ADT** implementation in C. It mimics the functionality of dynamic strings found in standard libraries (such as C++'s `std::string`) by managing dynamic memory allocation (`malloc`, `realloc`, `free`) behind a clean API.

### 🏗️ Data Structure Architecture
The dynamic string is represented using a custom `struct`:

```c
typedef struct S {
    char *str;  // Pointer to dynamic character array
    int size;   // Total allocated capacity
    int n;      // Current string length
} S;

| Function       | Signature                             | Description                                            | Time Complexity |
| :------------- | :------------------------------------ | :----------------------------------------------------- | :-------------- |
| `create`       | `void create(S *s, char c[])`         | Initializes a string from a standard C-string.         | O(N)            |
| `push_back`    | `void push_back(S *s, char c)`        | Appends a single character (resizes if full).          | Amort. O(1)     |
| `pop_back`     | `void pop_back(S *s)`                 | Removes the last character.                            | O(1)            |
| `size`         | `int size(S *s)`                      | Returns current character count.                       | O(1)            |
| `at_index`     | `char at_index(S *s, int in)`         | Accesses character at index `in`.                      | O(1)            |
| `clear`        | `void clear(S *s)`                    | Clears text content without freeing the buffer.        | O(1)            |
| `concat`       | `void concat(S *m, S *pat)`           | Concatenates string `pat` onto string `m`.             | O(M)            |
| `insert_at`    | `void insert_at(S *s, char c, int in)`| Inserts character at given index, shifting elements.   | O(N)            |
| `delete_at`    | `void delete_at(S *s, int in)`        | Deletes character at given index, shifting elements.   | O(N)            |
| `replace_at`   | `void replace_at(S *s, char c, int in)`| Overwrites character at target index.                 | O(1)            |
| `find_substring`| `int find_substring(S *s, S *pat)`   | Naive pattern matching. Returns start index or `-1`.   | O(N * M)        |
| `display`      | `void display(S *s)`                  | Prints string content to stdout.                       | O(N)            |
| `Free`         | `void Free(S *s)`                     | Frees allocated memory and safely resets pointers.     | O(1)            |
