//
// Created by salih on 22.12.2021.
//

#ifndef ASS4_EXECUTOR_H
#define ASS4_EXECUTOR_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include "vector"
#include "Helper.h"

struct Node{

    string key="61";// initial value to check is it blank // doth style
    string value="61";// initial value to check is it blank // eng style

    vector<Node*> children;

};

struct less_than_key
{
    inline bool operator() (const Node& struct1, const Node& struct2)
    {
        return (struct1.key < struct2.key);
    }
};

using namespace std;
class Executor {

public:


    static void execute(string input, string output);
    static void insert(vector<Node> &vector,string key, string value, string &message);
    static void search(vector<Node> &vec ,string key, string &message);
    static void del(vector<Node> &vec ,string key, string &message);
    static void list(vector<Node> &vec, string &message);
private:


};

#endif //ASS4_EXECUTOR_H
