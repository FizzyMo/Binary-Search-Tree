<h1 align="center">Binary Search Tree (BST) Implementation and Analysis</h1>

This project demonstrates the implementation and analysis of a Binary Search Tree (BST) in C++. The BST is a fundamental data structure that enables practical insertion, deletion, and search operations.
The implementation contains error handling, file handling, and traversal methods, giving a complete picture of how data structures can be used to manage and alter data.
***
## Table of Contents

- [Software Solutions](#software-solutions)
- [Node Structure](#node-structure)
- [Binary Search Tree Operations](#binary-search-tree-operations)
- [File Handling and Error Management](#file-handling-and-error-management)
- [Analysis Data Structure](#analysis-data-structure)
- [Technology Stack](#technology-stack)
- [Project Structure](#project-structure)
- [How to Run](#how-to-run)
- [Author](#author)
- [Contact](#contact)
***

### Software Solutions
In this project, several software solutions were utilized to effectively implement and analyze the Binary Search Tree:

1. **Visual Studio Code (VSC)***
   * **Solution:** VSC was used as the primary IDE to write, compile, and debug the C++ code. Its integrated terminal and support for extensions made it easier to manage the project's development environment.
   * **Implementation:** The code was developed using VSC's code editor, which provided features like syntax highlighting, code snippets, and error detection. This ensured a smooth and efficient coding process.
   * **Analysis:** VSC's debugging tools were used to step through the code, analyze the flow of execution, and identify any logical errors, particularly during the implementation of the BST operations.

2. **GitHub**
   * **Solution:** GitHub was used to manage version control for the project and tracking of changes over time.
   * **Implementation:** The project was initialized as a Git repository and pushed to GitHub. Commits were made regularly to document changes and improvements in the code.
   * **Analysis:** GitHub's commit history and pull request features allowed for code review and analysis, ensuring that the implementation of the BST was both correct and optimized.

3. **Error Handling Mechanisms**
   * **Solution:** Robust error handling was incorporated into the code to ensure that the program could gracefully handle unexpected inputs and conditions.
   * **Implementation:** Functions such as `remove` include checks to ensure that the value exists in the tree before attempting to delete it. If the value is not found,
     the program prompts the user to select a valid number.
   * **Analysis:** The error handling mechanisms were tested using edge cases to ensure that the BST operations remained stable and provided appropriate feedback to the user.

### Node Structure
The `Node` class represents each node within the BST. Each node contains:
* **data:** An integer value stored in the node.
* **left:** A pointer to the left child node.
* **right:** A pointer to the right child node.
This structure is fundamental to the BST, where each node's left child contains values less than the node’s value, and the right child contains values greater than the node’s value.

### Binary Search Tree Operations
The `BinarySearchTree` class encapsulates the BST operations:
* **Insert:** Adds a new value to the BST, ensuring the tree maintains its properties. The value is inserted in the appropriate position to keep the tree balanced.
* **Delete:** Removes a value from the BST. The function handles three cases:
  * Node with no children (leaf node).
  * Node with one child.
  * Node with two children (the node is replaced with its inorder successor).
* **Find Maximum:** Traverses the tree to find and return the maximum value, which is located at the rightmost node.
* **Traversals:**
  * **Inorder:** Traverses the tree in ascending order (left, root, right).
  * **Preorder:** Traverses the tree starting from the root (root, left, right).
  * **Postorder:** Traverses the tree where the root is visited last (left, right, root).

### File Handling and Error Management
The program reads integers from a file `data.txt` and inserts them into the BST upon startup. It displays the contents of the file before any operation is performed.
* **File Handling:** The program reads each integer from `data.txt` and inserts it into the BST. The integers are also stored in a set to facilitate quick lookups.
* **Error Handling:**
  * **Delete Operation:** Before deleting a node, the program checks if the value exists in the set
    (representing values from the file). If the value does not exist, the user is prompted to select a valid number from the list of available integers.

### Analysis Data Structure
The Binary Search Tree (BST) is an efficient data structure for organizing and searching data. Here’s how it was analyzed in this project
### Efficiency
  * **Insertion:** Inserting an element into a BST is efficient, with an average time complexity of O(log n). This efficiency is achieved because the tree maintains its sorted order, allowing for quick insertion at the correct position.
  * **Deletion:** Deletion in a BST is slightly more complex due to the need to maintain the tree's structure. The time complexity remains O(log n) on average, though it can degrade to O(n) in the worst case (unbalanced tree).
  * **Search:** Searching for an element in a BST is O(log n) on average, making it efficient for large datasets.

### Balancing
* A BST can become unbalanced if elements are inserted in a non-random order (e.g., sorted order).
This project does not implement self-balancing mechanisms like AVL or Red-Black Trees but provides a good foundation for understanding the basic BST operations.

### Traversal Analysis
* **Inorder Traversal:** Produces a sorted list of elements, which is useful for analyzing the tree's structure.
* **Preorder and Postorder Traversals:** Useful for understanding the tree's hierarchical structure and for various tree-based algorithms.

### Technology Stack
* **Visual Studio:** Integrated Development Environment (IDE) used for writing, debugging, and testing the C++ code.
* **GitHub:** Version control platform used to manage the project's source code and track changes over time.

### Project Structure
The project consists of the following files:
* **Binary.cpp:** The main C++ source file containing the implementation of the BST and associated operations.
* **data.txt:** A text file containing a list of integers that are read into the BST at runtime.

## How to Run
To run the Binary Search Tree program, follow these steps:
1. **Clone the Repository**
   * If you haven't already, clone the repository from GitHub to your local machine:
     <br>`git clone https://github.com/YourUsername/BinarySearchTree.git`<br> `cd BinarySearchTree`
2. **Prepare the Data**
   * Ensure that the `data.txt` file is present in the project directory. This file should contain integers that you want to insert into the BST, each on a new line.
3. **Open the Project in Visual Studio**
   * Launch Visual Studio.
   * Select **File** > **Open** > **Project/Solution.**
   * Navigate to the `Binary.sln` file in the cloned repository, and open it.
   * Visual Studio will automatically create a project for the `.cpp` file.
4. **Set Up the Project**
   * Ensure that `Binary.cpp` is set as the startup file. Right-click on `Binary.cpp` in the Solution Explorer and select **Set as Startup Item.**
   * Include the `data.txt` file in the project directory. To do this, right-click on the project in Solution Explorer, choose **Add** > **Existing Item** and select `data.txt`.
5. **Compile and Run the Program**
   * To compile the program, go to the menu and select **Build** > **Build Solution.**
   * If the build is successful, run the program by selecting **Debug** > **Start Without Debugging** (or press `Ctrl + F5`).
6. **Interact with the Program**
   * The program will display a menu with options to insert, delete, find the maximum, and perform tree traversals. Follow the on-screen prompts to interact with the Binary Search Tree.

 ## Author
**Carisa Saenz-Videtto**

## Contact
carisasaenz@gmail.com
