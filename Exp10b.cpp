#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Build the tree recursively
Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    Node* root = new Node(val);
    cout << "Enter left of " << val << " (-1 to stop): ";
    root->left = buildTree();
    cout << "Enter right of " << val << " (-1 to stop): ";
    root->right = buildTree();
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int choice;

    while (true) {
        cout << "\n===== BINARY TREE MENU =====" << endl;
        cout << "1. Build/Create Tree" << endl;
        cout << "2. Preorder Traversal" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Postorder Traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter root value (-1 for none): ";
                root = buildTree();
                break;
            case 2:
                if (!root) cout << "Tree is empty!";
                else { cout << "Preorder: "; preorder(root); }
                cout << endl;
                break;
            case 3:
                if (!root) cout << "Tree is empty!";
                else { cout << "Inorder: "; inorder(root); }
                cout << endl;
                break;
            case 4:
                if (!root) cout << "Tree is empty!";
                else { cout << "Postorder: "; postorder(root); }
                cout << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}