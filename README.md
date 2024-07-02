# Tree and Iterators Project
## Overview

This project implements a generic tree data structure in C++ with various traversal iterators and a visualization feature using SFML. The tree supports multiple child nodes and provides iterators for pre-order, in-order, post-order, breadth-first, depth-first, and heap traversal. Additionally, nodes can be visualized graphically to resemble a tree structure.
## Class Descriptions
### Tree Class

    Functionality: Manages a tree data structure with a specified maximum number of child nodes per parent.
    Features:
        Add root and child nodes
        Pre-order, in-order, post-order, BFS, DFS, and heap traversal iterators
        Print the tree structure in a textual format
        Visualize the tree using SFML

### Node Class

    Functionality: Represents a node in the tree.
    Features:
        Store a value and a list of child nodes
        Add child nodes
        Retrieve the node's value and children

### Iterator Classes

    Functionality: Provide various traversal mechanisms for the tree.
    Features:
        PreOrderIterator: Traverse the tree in pre-order
        InOrderIterator: Traverse the tree in in-order
        PostOrderIterator: Traverse the tree in post-order
        BFSIterator: Traverse the tree in breadth-first order
        DFSIterator: Traverse the tree in depth-first order
        HeapifyIterator: Convert the tree to a min-heap and traverse it

## How to Build and Run
### Prerequisites

    SFML library
    A C++ compiler (g++)
