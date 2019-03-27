#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {
    string name;
    vector<node*> children;
} node;

node* findNode(node* parent, const string &name) {
    for (auto &i : parent->children) {
        if (i->name == name) {
            return i;
        }
    }
    return nullptr;
}

void addNode(node* root_node, vector<string> paths, int i) {
    if (i < paths.size()) {
        node *current = findNode(root_node, paths.at(i));
        i++;
        if (current == nullptr) {
            current = (node *) malloc(sizeof(node));
            current->name = paths.at(i - 1);
            root_node->children.push_back(current);
        }
        addNode(current, paths, i);
    }
}

bool compareByLength(node* a, node* b)
{
    return a->name < b->name;
}

void printTree(node* root_node, int space) {
    sort(root_node->children.begin(), root_node->children.end(), compareByLength);
    for (int i = 0; i < root_node->children.size(); i++) {
            for (int j = 0; j < space; j++) {
                cout << " ";
            }
            if (root_node->name == "\\" && i == root_node->children.size() - 1) {
                cout << root_node->children.at(i)->name;
            } else {
                cout << root_node->children.at(i)->name << endl;
            }
        printTree(root_node->children.at(i), space + 1);
    }
}


int main() {
    int n;
    cin >> n;

    node root_node;
    root_node.name = "\\";

    string path;
    for (int j = 0; j < n; j++) {
        cin >> path;
        vector<string> paths;
        unsigned int i = 0;
        while (i <= path.size()) {
            string tmp;
            while (i < path.size() && path[i] != '\\') {
                tmp += path[i];
                i++;
            }
            paths.push_back(tmp);
            i++;
        }

        addNode(&root_node, paths, 0);

    }

    printTree(&root_node, 0);

    return 0;
}
