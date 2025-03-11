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


};



#endif //SCHOOLBST_H
