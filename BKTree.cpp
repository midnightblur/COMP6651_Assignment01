//
// Created by Quoc Minh Vu on 2017-09-29.
//

#include "BKTree.h"

void BKTree::addNode(const string &word) {
    BKNode *newNode = new BKNode(word);
    if (root == nullptr)
        root = newNode;
    else
        root->addChild(newNode);
}

std::ostream &operator<<(std::ostream &out, BKTree &bkTree) {
    out << *(bkTree.root) << endl;
    return out;
}

std::vector<string> BKTree::getSuggestedWords(string &word, int distance, bool &isInDict) const {
    std::vector<string> result;
    std::queue<BKNode*> candidates;
    candidates.push(root);
    while (!candidates.empty()) {
        BKNode *currentCandidate = candidates.front();
        candidates.pop();

        int radius = Levenshtein::measureDistance(word, currentCandidate->word);

        if (radius == 0) {
            isInDict = true;
            result.clear();
            return result;
        }

        if (radius <= distance)
            result.push_back(currentCandidate->word);

        int minDistance = (radius - distance < 0) ? 0 : radius - distance;
        int maxDistance = radius + distance;

        for (int i = minDistance; i <= maxDistance; i++) {
            if (currentCandidate->children.find(i) != currentCandidate->children.end())
                candidates.push(currentCandidate->getChildAtDistance(i));
        }
    }
    return result;
}
