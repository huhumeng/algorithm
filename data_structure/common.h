#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template <typename T>
ostream &operator<<(ostream &os, const vector<T, allocator<T>> &vec) {

    for (auto &v : vec) {
        os << v << " ";
    }

    return os;
}

template <typename T>
ostream &operator>>(ostream &os, const vector<vector<T>> &vec) {

    for (auto &v : vec) {
        os << v << "\n";
    }

    return os;
}