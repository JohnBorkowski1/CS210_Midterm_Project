//
// Created by johnb on 3/11/2025.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#ifndef SCHOOLBST_H
#define SCHOOLBST_H

struct School {
    string name, address, city, state, county;
};


struct Node {
    School data;
    Node* left;
    Node* right;
    Node(School school) : data(school), left(nullptr), right(nullptr) {}
};

class SchoolBST {
private:
    Node* root;

    Node* insert(Node* root, School school) {
        if (!root) return new Node(school);
        if (school.name < root->data.name)
            root->left = insert(root->left, school);
        else
            root->right = insert(root->right, school);
        return root;
    }

    void displayInOrder(Node* root) {
        if (!root) return;
        displayInOrder(root->left);
        cout << root->data.name << "\n";
        displayInOrder(root->right);
    }

    void displayPreOrder(Node* root) {
        if (!root) return;
        cout << root->data.name << "\n";
        displayPreOrder(root->left);
        displayPreOrder(root->right);
    }

    void displayPostOrder(Node* root) {
        if (!root) return;
        displayPostOrder(root->left);
        displayPostOrder(root->right);
        cout << root->data.name << "\n";
    }

    Node* minValueNode(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* deleteByName(Node* root, string name) {
        if (!root) return root;
        if (name < root->data.name)
            root->left = deleteByName(root->left, name);
        else if (name > root->data.name)
            root->right = deleteByName(root->right, name);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteByName(root->right, temp->data.name);
        }
        return root;
    }

    Node* findByName(Node* root, string name) {
        if (!root || root->data.name == name) return root;
        if (name < root->data.name) return findByName(root->left, name);
        return findByName(root->right, name);
    }

public:
    SchoolBST() : root(nullptr) {}

    void insert(School school) { root = insert(root, school); }
    void displayInOrder() { displayInOrder(root); }
    void displayPreOrder() { displayPreOrder(root); }
    void displayPostOrder() { displayPostOrder(root); }

    School* findByName(string name) {
        Node* result = findByName(root, name);
        return result ? &result->data : nullptr;
    }

    void deleteByName(string name) { root = deleteByName(root, name); }
};



#endif //SCHOOLBST_H
