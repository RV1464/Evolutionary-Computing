# Evolutionary_Computing
## Graph Search Algorithms in C

This repository contains implementations of various **graph search algorithms** in C.  
Each program reads graph input from the user (number of vertices, edges, and optionally weights or heuristics)  
and demonstrates a specific search technique.

---

## 📜 List of Algorithms

### 1. British Museum Search (BMS)
- **Type**: Brute-force search.
- **Description**: Explores **all possible paths** blindly until a solution is found.  
  Inefficient but guarantees a solution if one exists.

### 2. Depth-First Search (DFS)
- **Type**: Uninformed search.
- **Description**: Recursively explores as deep as possible along each branch before backtracking.

### 3. Breadth-First Search (BFS)
- **Type**: Uninformed search.
- **Description**: Explores neighbors level-by-level, guaranteeing the shortest path in an unweighted graph.

### 4. DFS + History
- **Type**: DFS variant.
- **Description**: DFS that **remembers visited nodes** to avoid cycles and repeated states.

### 5. BFS + History
- **Type**: BFS variant.
- **Description**: BFS with a visited set to avoid revisiting nodes.

### 6. DFS + BFS Hybrid
- **Type**: Hybrid search.
- **Description**: Combines DFS depth exploration with BFS-like expansion at certain stages.

### 7. Beam Search (BS)
- **Type**: Heuristic search.
- **Description**: Explores only a fixed number (`beam width`) of best nodes at each level based on heuristic values.

### 8. Hill Climbing (HC)
- **Type**: Heuristic search.
- **Description**: Moves to the neighbor with the best heuristic value until no improvement is found.  
  May get stuck at local maxima.

### 9. Beam Search + History
- **Type**: Beam search variant.
- **Description**: Beam search that avoids revisiting already expanded nodes.

### 10. Hill Climbing + History
- **Type**: Hill climbing variant.
- **Description**: Hill climbing that avoids revisiting nodes or paths that lead to dead ends.

### 11. Oracle Search
- **Type**: Idealized heuristic search.
- **Description**: Uses **perfect knowledge** of distances to the goal to always choose the optimal step.

### 12. Branch and Bound (B&B)
- **Type**: Optimal search.
- **Description**: Expands the partial path with the **lowest cost so far** until the goal is reached.

### 13. Branch and Bound + Estimated Heuristics
- **Type**: Best-First Branch and Bound.
- **Description**: Expands nodes based on `cost_so_far + heuristic`, improving search efficiency.

### 14. A* Search
- **Type**: Optimal & Complete heuristic search.
- **Description**: Classical A* using `f(n) = g(n) + h(n)` for guaranteed optimal pathfinding with admissible heuristics.



