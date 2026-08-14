# Lab 07: Graphs

This directory contains C and C++ implementations of fundamental graph data structures and common graph algorithms. It serves as a practical exploration of how graphs can be represented in memory and how to traverse or analyze them to solve pathfinding and spanning tree problems.

## 📂 Repository Contents

### Graph Representations (Data Structures)
These files demonstrate different ways to store graph data in memory depending on the density of the graph and the specific operations required.

*   **`AdjacencyMatrix.c`**: Implements a graph using a 2D array (matrix). This is highly efficient for edge lookups and dense graphs but consumes $O(V^2)$ space.
*   **`AdjacencyList.c`**: Implements a graph using an array of linked lists. This is much more space-efficient for sparse graphs, using $O(V + E)$ space, and allows for efficient iteration over a vertex's neighbors.
*   **`EdgeList.c`**: Represents a graph simply as an unordered list (or array) of its edges. This is often used as the underlying structure for algorithms like Kruskal's.

### Graph Algorithms
These files contain implementations of standard algorithms used to solve complex problems on graphs.

*   **`dijkstras.cpp`**: An implementation of Dijkstra's Algorithm. This algorithm finds the shortest path from a single source node to all other nodes in a weighted graph with non-negative edge weights.
*   **`kruskal.cpp`**: An implementation of Kruskal's Algorithm. This is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph.
