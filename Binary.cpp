// Header, standard for input and output operations
#include <iostream>

// Header, to perform input and output operations on files
#include <fstream>  

// Header, access to a container that sorts elements 
#include <set>

// Node structure for Binary Search Tree
class Node {
public:
    // Data stored in the node
    int data;
    // Pointer to the left child
    Node* left;
    // Pointer to the right child
    Node* right;

    // Constructor to initialize a new node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    // Pointer to the root of the BST
    Node* root;

    // Recursive function to insert a value into the BST
    Node* insert(Node* node, int value) {

        // Base case: If the current node is null, create a new node with the value
        if (node == nullptr) {
            return new Node(value);
        }
        // Recursive steps
        if (value < node->data) {
            // If the value is less than the current node's data, go to the left subtree
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            // If the value is greater than the current node's data, go to the right subtree
            node->right = insert(node->right, value);
        }
        // If the value is already present, do nothing (no duplicates in BST)
        return node;
    }

    // Recursive function to delete a node with a given value from the BST
    Node* deleteNode(Node* node, int value) {
        // Base case: If the tree is empty
        if (node == nullptr) {
            return node;
        }
        // Recursive steps: Search for the node to delete
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            // Case 1 & 2: Node with one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Node with two children, find inorder (smallest in the right subtree)
            Node* temp = findMin(node->right);
            // Copy inorder successor's data to this node
            node->data = temp->data;
            // Delete the inorder successor
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    // Helper function to find the node with the minimum value in a subtree
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to find the node with the maximum value in a subtree
    Node* findMax(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // Recursive function for inorder traversal of the BST
    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        // Traverse left subtree
        inorderTraversal(node->left);
        // Visit the node(print its data)
        std::cout << node->data << " ";
        // Traverse right subtree
        inorderTraversal(node->right);
    }

    // Recursive function for preorder traversal of the BST
    void preorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // Recursive function for postorder traversal of the BST
    void postorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->data << " ";
    }

    //Insert, remove, findMaximum, traversal functions
public:
    // Constructor to initialize an empty BST
    BinarySearchTree() : root(nullptr) {}
    // Public function to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Public function to delete a node with a given value from the BST
    void remove(int value) {
        root = deleteNode(root, value);
    }

    // Public function to find the maximum value in the BST
    int findMaximum() {
        if (root == nullptr) {
            // Throw an error if the tree is empty
            throw std::runtime_error("Tree is empty.");
        }

        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }

    // Public function to perform and print inorder traversal
    void inorderTraverse() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    // Public function to perform and print preorder traversal
    void preorderTraverse() {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    // Public function to perform and print postorder traversal
    void postorderTraverse() {
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;
    std::set<int> valuesInFile;

    // Open the input file "data.txt" for reading
    std::ifstream inputFile("data.txt");
    int value;

    // Read and display integers from the file before inserting them into the BST
    std::cout << "Integers in the file:" << std::endl;
    while (inputFile >> value) {
        // Display the integer
        std::cout << value << " ";
        // Insert the integer into the BST
        bst.insert(value);
        // Store the integer in the set
        valuesInFile.insert(value);
    }
    // Add a new line after displaying the integers
    std::cout << std::endl;

    // Close the file after reading
    inputFile.close();

    int choice;
    //Display menu options
    while (true) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Insert" << std::endl;
        std::cout << "2. Delete" << std::endl;
        std::cout << "3. Find Maximum" << std::endl;
        std::cout << "4. Inorder Traverse" << std::endl;
        std::cout << "5. Preorder Traverse" << std::endl;
        std::cout << "6. Postorder Traverse" << std::endl;
        std::cout << "7. Exit" << std::endl;

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\nEnter value to insert: ";
            std::cin >> value;
            bst.insert(value);
            valuesInFile.insert(value);
            break;
        case 2:
            std::cout << "\nEnter value to delete: ";
            std::cin >> value;
            if (valuesInFile.find(value) != valuesInFile.end()) {
                bst.remove(value);
                valuesInFile.erase(value); 
                std::cout << "Value deleted." << std::endl;
            }
            else {
                std::cout << "Value not found in the file. Please choose a valid number from the list." << std::endl;
                std::cout << "Valid numbers: ";
                for (int v : valuesInFile) {
                    std::cout << v << " ";
                }
                std::cout << std::endl;
            }
            break;
        case 3:
            try {
                int maxVal = bst.findMaximum();
                std::cout << "\nMaximum Value: " << maxVal << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 4:
            std::cout << "\nInorder Traversal: ";
            bst.inorderTraverse();
            break;
        case 5:
            std::cout << "\nPreorder Traversal: ";
            bst.preorderTraverse();
            break;
        case 6:
            std::cout << "\nPostorder Traversal: ";
            bst.postorderTraverse();
            break;
        case 7:
            return 0;
        default:
            std::cout << "Invalid choice." << std::endl;
        }
    }

    return 0;
}
