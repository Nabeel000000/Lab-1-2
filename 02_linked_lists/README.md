#Linked List Implementation (`02_linked_lists`)

## 📌 Overview
This directory contains a complete, robust implementation of a **Singly Linked List** in C, wrapped using structured types (`LL` for the list container and `Node` for individual data elements) to track element count and manage dynamic allocations safely.

---

## 🏗️ Data Structure Architecture

| Operation / Function | Average Case | Worst Case | Description |
| :--- | :--- | :--- | :--- |
| **Access / Search by Index** | O(N) | O(N) | Must traverse from the head node to the target index. |
| **Search by Value** | O(N) | O(N) | Linear scan through nodes to find the target value. |
| **Insertion at Head** (`push_front`) | O(1) | O(1) | Direct pointer update at the beginning of the list. |
| **Insertion at Tail** (`push_back`) | O(N) | O(N) | Requires traversing to the end of the list. |
| **Insertion at Index** (`insert_at`) | O(N) | O(N) | Traverses to the target position to insert the node. |
| **Deletion at Head** | O(1) | O(1) | Updates the head pointer to the next node. |
| **Deletion at Index** (`delete_at`) | O(N) | O(N) | Traverses to the target index to unlink and free the node. |
| **Get Size / Check Empty** | O(1) | O(1) | Directly accesses pre-maintained counters or pointers in the `LL` struct. |
| **Free List** | O(N) | O(N) | Iterates through every node to deallocate memory. |
