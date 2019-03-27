#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct node{
    map<string, node*> link;
};

node nodes[100000];
long index = 1;

node* addNode(node* root, string name) {
    auto& child = root->link[name];
    if (!child) child = &nodes[index++];
    return  child;
}

void printDir(node* root, string spaces) {
    for (auto link :  root->link) {
        cout << spaces << link.first << endl;
        printDir(link.second, spaces + " ");

    }
}

int main() {
    int n;
    cin >> n;
    string path, name;
    for (int j = 0; j < n; j++) {
        cin >> path;
        stringstream ss(path);

        node* current_node = &nodes[0];
        while (getline(ss, name, '\\')) {
            current_node = addNode(current_node, name);
        }

    }

    stringstream out;
    printDir(&nodes[0], "");

    return 0;
}