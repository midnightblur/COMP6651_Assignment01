//
// Created by Quoc Minh Vu on 2017-09-29.
//

#include "Levenshtein.h"

/**
 * Reference: https://people.cs.pitt.edu/~kirk/cs1501/Pruhs/Spring2006/assignments/editdistance/Levenshtein%20Distance.htm
 * @param source
 * @param target
 * @return
 */
int Levenshtein::measureDistance(const string &source, const string &target) {
    /* Step 1 */
    auto n = static_cast<unsigned int>(source.size());
    auto m = static_cast<unsigned int>(target.size());

    if (n == 0)
        return m;
    if (m == 0)
        return n;

    int **matrix;
    matrix = new int *[m + 1];
    for (int j = 0; j <= m; j++) {
        matrix[j] = new int[n + 1];
    }

    /* Step 2 */
    for (int i = 0; i <= n; i++)
        matrix[0][i] = i;
    for (int j = 0; j <= m; j++)
        matrix[j][0] = j;

    /* Step 3 - 6 */
    for (unsigned int i = 1; i <= n; i++) {
        for (unsigned int j = 1; j <= m; j++) {
            int cost;
            if (source.at(i - 1) == target.at(j - 1))
                cost = 0;
            else
                cost = 1;

            matrix[j][i] = std::min(matrix[j][i - 1] + 1, std::min(matrix[j - 1][i] + 1, matrix[j - 1][i - 1] + cost));
        }
    }

    return matrix[m][n];
}