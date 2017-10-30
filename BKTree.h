//
// Created by Quoc Minh Vu on 2017-09-29.
//

#ifndef COMP6651_ASSIGNMENT01_BKTREE_H
#define COMP6651_ASSIGNMENT01_BKTREE_H

#include <string>
#include <vector>
#include <map>
#include <ostream>
#include <queue>
#include "Levenshtein.h"

using std::string;
using std::endl;

class BKTree {
private:
    class BKNode {
    private:
        string word;
        std::map<int, BKNode*> children;
    public:
        BKNode(const string &word) : word(word) {}

        const string& getWord() const {
            return word;
        }

        BKNode* getChildAtDistance(int distance) {
            if (children.find(distance) != children.end())
                return children.at(distance);
            else
                return nullptr;
        }

        void addChild(BKNode *newNode) {
            int distance = Levenshtein::measureDistance(newNode->getWord(), this->getWord());
            BKNode *child = this->getChildAtDistance(distance);
            if (child == nullptr)
                children.insert(std::pair<int, BKNode*>(distance, newNode));
            else
                child->addChild(newNode);
        }

        friend std::ostream& operator<<(std::ostream& out, BKNode& bkNode) {
            out << bkNode.word << endl;
            for (auto iter = bkNode.children.begin(); iter != bkNode.children.end(); iter++) {
                out << *((*iter).second);
            }
            return out;
        }

        friend class BKTree;
    };
    BKNode *root;
public:
    BKTree() : root{nullptr} {}
    void addNode(const string &word);
    std::vector<string> getSuggestedWords(string &word, int distance, bool &isInDict) const;
    friend std::ostream& operator<<(std::ostream& out, BKTree& bkTree);
};

#endif //COMP6651_ASSIGNMENT01_BKTREE_H
