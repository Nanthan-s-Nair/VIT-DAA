# DAA LPS
This repository contains all lab codes for the Course : BCSE204P - Design and Analysis of Algorithms (DAA) at VIT Chennai. It includes solutions for each lab problem set, focusing on algorithm design principles and time complexity analysis.

Repository Structure
```
VIT-DAA/
├── LPS-1
│   ├── q1
│   │   ├── Solution code            # Code for solving the question
│   │   ├── Input generator          # Generates random inputs of different sizes
│   │   ├── Results                  # Stores results of runtime measurements
│   │   └── Graph notebook           # Plots runtime complexity using collected data
│   ├── q2
│   └── ...
│
├── LPS-2
│   ├── q1
│   ├── q2
│   └── ...
│
├── ...
│
├── LPS-N
│   ├── q1
│   └── ...
```

## Contents of Each LPS
- Each LPS directory includes:
  - Questions (q1, q2, …): Each question is contained in its own folder with:
  - Solution Code: Implements the algorithm for the specific problem.
  - Input Generator: Script (in C++ or Python) that generates random inputs of varying sizes to measure runtime.
  - Data File: Records the runtime results for different input sizes, typically in a CSV format.
  - Graph Notebook: Jupyter Notebook to visualize the time complexity by plotting the recorded data.

## How to Use
  1. Run Solution Code: Each question’s solution can be executed individually.
  2.	Run Input Generator: Use the input generator to create randomized inputs and log the runtime data.
  3.	Plot Graphs: Open the graph notebook to visualize time complexity using the recorded runtime data.

Each LPS explores time complexity and performance analysis in different ways, providing insights into algorithm efficiency.