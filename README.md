# Skip List Implementation

This project implements a Skip List, a probabilistic data structure that supports efficient search, insertion, and deletion operations. It includes advanced features such as submaps, headmaps, tailmaps, and key-based floor/ceiling operations.

## Compilation and Execution

### To compile the program:
```bash
gcc -o skiplist skiplist.c
```

### To run the compiled program:
```bash
./skiplist
```

## Example Usage

### Menu Options:
```text
1. Insert
2. Remove
3. Search
4. Size
5. IsEmpty
6. Clear
7. FloorKey
8. CeilingKey
9. LowerKey
10. HigherKey
11. SubMap
12. HeadMap
13. TailMap
14. Display
15. Exit
```

### Sample Interaction:

#### Insert:
```text
Enter key and value to insert: key1 100
Successfully Inserted key 'key1'
```

#### Display:
```text
**Skip List**
Level 0: (key1, 100)
```

#### Remove:
```text
Enter key to remove: key1
Successfully deleted key 'key1'
```

## Code Structure

### Header and Struct Definitions:
- **Node**: Represents a single node in the Skip List.
- **SkipList**: Contains metadata, including the header node, level, and size.

### Functions:
- **createNode**: Allocates memory for a new node.
- **createSkipList**: Initializes a Skip List.
- **randomLevel**: Generates random levels for balancing.
- **insert**: Inserts a key-value pair.
- **search**: Finds the value associated with a key.
- **removeElement**: Removes a node by key.
- **size**: Returns the size of the Skip List.
- **isEmpty**: Checks if the Skip List is empty.
- **clear**: Deletes all elements in the Skip List.
- **subMap**: Creates a submap from `fromKey` to `toKey`.
- **headMap**: Creates a headmap up to `toKey`.
- **tailMap**: Creates a tailmap from `fromKey`.
- **floorKey**: Finds the largest key ≤ the given key.
- **ceilingKey**: Finds the smallest key ≥ the given key.
- **lowerKey**: Finds the largest key < the given key.
- **higherKey**: Finds the smallest key > the given key.
- **displayList**: Prints all nodes at each level.

## Customization

- Modify the probability factor `P` to adjust balancing behavior.
- Extend the menu options or integrate additional operations as needed.

## License

This project is open-source and free to use under the MIT License.

## Acknowledgments

- Inspired by the concept of Skip Lists introduced by William Pugh.
- Designed for educational purposes and demonstration of data structures.

## Contributing

Feel free to open issues or submit pull requests if you'd like to contribute or suggest enhancements.
