//
// Created by 欧阳松 on 2019-03-08.
//

#ifndef LEETCODE_CPP_STRUCTS_H
#define LEETCODE_CPP_STRUCTS_H

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) {};
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

template<class types>
void print(vector<types> vec) {
    for (auto v: vec) cout << v << " ";
    cout << endl;
}

template<class types>
void print(vector<vector<types> > vec) {
    for (auto v: vec) {
        for (auto p: v) cout << p << " ";
        cout << endl;
    }
    cout << endl;
}

template<class types>
void print(vector<pair<types, types> > vec) {
    for (auto v: vec) cout << "(" << v.first << "," << v.second << ")" << " ";
    cout << endl;
}

template<class types>
void print(map<types, types> mp) {
    for (auto it: mp) cout << "(" << it.first << "," << it.second << ")" << " ";
    cout << endl;
}

template<class types>
void print(unordered_map<types, types> mp) {
    for (auto it: mp) cout << "(" << it.first << "," << it.second << ")" << " ";
    cout << endl;
}

template<class types>
void print(multimap<types, types> mp) {
    for (auto it: mp) cout << "(" << it.first << "," << it.second << ")" << " ";
    cout << endl;
}

template<class types>
void print(set<types> st) {
    for (auto it: st) cout << it << " ";
    cout << endl;
}

template<class types>
void print(unordered_set<types> st) {
    for (auto it: st) cout << it << " ";
    cout << endl;
}

template<class types>
void print(multiset<types> st) {
    for (auto it: st) cout << it << " ";
    cout << endl;
}

#endif //LEETCODE_CPP_STRUCTS_H
