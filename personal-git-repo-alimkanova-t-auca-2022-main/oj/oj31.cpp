#include "iostream"
#include "string"

using namespace std;
struct node {
    int value;
    node *left;
    node *right;
};

int sumTheTreeValues(node *root) {
    if (root == nullptr) {
        return 0;
    }
    int result = root->value + sumTheTreeValues(root->left) + sumTheTreeValues(root->right);
    return result;

}

int main() {
    node nodes = {10, new node{1, nullptr, nullptr}, new node{2, nullptr, nullptr}};
    cout << sumTheTreeValues(&nodes);
    return 0;
}