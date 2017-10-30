#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include "Levenshtein.h"
#include "BKTree.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

const std::vector<string> readDictionary(const string &filePath);

const int readMaxDistance(const string &filePath);

const std::vector<string> readSentence(const string &filePath);

void linearSearch(const std::vector<string> &dictionary, const int maxDistance, const std::vector<string> &words,
                  const string &resultFilePath);

void bkTreeSearch(const BKTree &bkTree, const int maxDistance, const std::vector<string> &words,
                  const string &resultFilePath);

const BKTree buildBKTree(const std::vector<string> &dictionary);

void experiment_1();
void experiment_2();
void experiment_3();
void experiment_4();

int main() {
    experiment_1();
    experiment_2();
    experiment_3();
    experiment_4();

    return 0;
}

void experiment_4() {
    cout << "EXPERIMENT 4" << endl;
    /* Build dictionary */
    clock_t dict_t1 = clock();
    const std::vector<string> DICTIONARY = readDictionary("/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/eng_370k.txt");
    clock_t dict_t2 = clock();
    float dict_diff((float) dict_t2 - (float) dict_t1);
    cout << "Finish building dictionary in " << dict_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl;

    /* Build BK Tree */
    clock_t tree_t1 = clock();
    const BKTree BKTREE = buildBKTree(DICTIONARY);
    clock_t tree_t2 = clock();
    float tree_diff((float) tree_t2 - (float) tree_t1);
    cout << "Finish building BK Tree in " << tree_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl << endl;

    const int DISTANCE_1 = readMaxDistance(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/distance_1.txt");
    const int DISTANCE_2 = readMaxDistance(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/distance_2.txt");
    const int DISTANCE_3 = readMaxDistance(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/distance_3.txt");
    const int DISTANCE_4 = readMaxDistance(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/distance_4.txt");
    const int DISTANCE_5 = readMaxDistance(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/distance_5.txt");

    const std::vector<string> WORDS = readSentence(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/sentence.txt");

    linearSearch(DICTIONARY, DISTANCE_1, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, DISTANCE_1, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsBKTree.txt");

    linearSearch(DICTIONARY, DISTANCE_2, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, DISTANCE_2, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsBKTree.txt");

    linearSearch(DICTIONARY, DISTANCE_3, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, DISTANCE_3, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsBKTree.txt");

    linearSearch(DICTIONARY, DISTANCE_4, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, DISTANCE_4, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsBKTree.txt");

    linearSearch(DICTIONARY, DISTANCE_5, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, DISTANCE_5, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase4/MisspelledWordsBKTree.txt");
}

void experiment_3() {
    cout << "EXPERIMENT 3" << endl;
    /* Build dictionary */
    clock_t dict_t1 = clock();
    const std::vector<string> DICTIONARY = readDictionary("/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/eng_70k.txt");
    clock_t dict_t2 = clock();
    float dict_diff((float) dict_t2 - (float) dict_t1);
    cout << "Finish building dictionary in " << dict_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl;

    /* Build BK Tree */
    clock_t tree_t1 = clock();
    const BKTree BKTREE = buildBKTree(DICTIONARY);
    clock_t tree_t2 = clock();
    float tree_diff((float) tree_t2 - (float) tree_t1);
    cout << "Finish building BK Tree in " << tree_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl << endl;

    const int MAX_DISTANCE = readMaxDistance(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/distance_1.txt");

    const std::vector<string> LENGTH_2_WORDS = readSentence(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/eng_length_2_sentence.txt");
    const std::vector<string> LENGTH_5_WORDS = readSentence(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/eng_length_5_sentence.txt");
    const std::vector<string> LENGTH_10_WORDS = readSentence(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/eng_length_10_sentence.txt");
    const std::vector<string> LENGTH_20_WORDS = readSentence(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/eng_length_20_sentence.txt");
    const std::vector<string> LENGTH_30_WORDS = readSentence(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/eng_length_22_sentence.txt");

    linearSearch(DICTIONARY, MAX_DISTANCE, LENGTH_2_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, MAX_DISTANCE, LENGTH_2_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsBKTree.txt");

    linearSearch(DICTIONARY, MAX_DISTANCE, LENGTH_5_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, MAX_DISTANCE, LENGTH_5_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsBKTree.txt");

    linearSearch(DICTIONARY, MAX_DISTANCE, LENGTH_10_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, MAX_DISTANCE, LENGTH_10_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsBKTree.txt");

    linearSearch(DICTIONARY, MAX_DISTANCE, LENGTH_20_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, MAX_DISTANCE, LENGTH_20_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsBKTree.txt");

    linearSearch(DICTIONARY, MAX_DISTANCE, LENGTH_30_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, MAX_DISTANCE, LENGTH_30_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase3/MisspelledWordsBKTree.txt");
}

void experiment_2() {
    cout << "EXPERIMENT 2" << endl;
    /* Build English dictionary */
    clock_t dict_t1 = clock();
    const std::vector<string> ENG_DICT = readDictionary("/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/eng_70k.txt");
    clock_t dict_t2 = clock();
    float dict_diff((float) dict_t2 - (float) dict_t1);
    cout << "Finish building English dictionary in " << dict_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl;

    /* Build English BK Tree */
    clock_t tree_t1 = clock();
    const BKTree ENG_BKTREE = buildBKTree(ENG_DICT);
    clock_t tree_t2 = clock();
    float tree_diff((float) tree_t2 - (float) tree_t1);
    cout << "Finish building English BK Tree in " << tree_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl << endl;

    /* Build randomized dictionary */
    dict_t1 = clock();
    const std::vector<string> RAND_DICT = readDictionary("/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/random_70k.txt");
    dict_t2 = clock();
    dict_diff = (float) dict_t2 - (float) dict_t1;
    cout << "Finish building randomized dictionary in " << dict_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl;

    /* Build randomized BK Tree */
    tree_t1 = clock();
    const BKTree RAND_BKTREE = buildBKTree(RAND_DICT);
    tree_t2 = clock();
    tree_diff = (float) tree_t2 - (float) tree_t1;
    cout << "Finish building randomized BK Tree in " << tree_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl << endl;

    const int MAX_DISTANCE = readMaxDistance(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/distance_1.txt");
    const std::vector<string> ENG_WORDS = readSentence(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/eng_short_sentence.txt");
    const std::vector<string> RAND_WORDS = readSentence(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/random_short_sentence.txt");

    linearSearch(ENG_DICT, MAX_DISTANCE, ENG_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/MisspelledWordsLinear.txt");
    bkTreeSearch(ENG_BKTREE, MAX_DISTANCE, ENG_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/MisspelledWordsBKTree.txt");

    linearSearch(RAND_DICT, MAX_DISTANCE, ENG_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/MisspelledWordsLinear.txt");
    bkTreeSearch(RAND_BKTREE, MAX_DISTANCE, ENG_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/MisspelledWordsBKTree.txt");

    linearSearch(ENG_DICT, MAX_DISTANCE, RAND_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/MisspelledWordsLinear.txt");
    bkTreeSearch(ENG_BKTREE, MAX_DISTANCE, RAND_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/MisspelledWordsBKTree.txt");

    linearSearch(RAND_DICT, MAX_DISTANCE, RAND_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/MisspelledWordsLinear.txt");
    bkTreeSearch(RAND_BKTREE, MAX_DISTANCE, RAND_WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase2/MisspelledWordsBKTree.txt");
}

void experiment_1() {
    cout << "EXPERIMENT 1" << endl;
    /* Build English dictionary */
    clock_t dict_t1 = clock();
    const std::vector<string> DICTIONARY = readDictionary("/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/eng_70k.txt");
    clock_t dict_t2 = clock();
    float dict_diff((float) dict_t2 - (float) dict_t1);
    cout << "Finish building dictionary in " << dict_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl;

    /* Build English BK Tree */
    clock_t tree_t1 = clock();
    const BKTree BKTREE = buildBKTree(DICTIONARY);
    clock_t tree_t2 = clock();
    float tree_diff((float) tree_t2 - (float) tree_t1);
    cout << "Finish building BK Tree in " << tree_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl << endl;

    const int MAX_DISTANCE = readMaxDistance(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/resources/distance_1.txt");
    const std::vector<string> WORDS = readSentence(
            "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase1/eng_short_sentence.txt");

    linearSearch(DICTIONARY, MAX_DISTANCE, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase1/MisspelledWordsLinear.txt");
    bkTreeSearch(BKTREE, MAX_DISTANCE, WORDS,
                 "/Users/midnightblur/Documents/workspace/CLionProjects/COMP6651_Assignment01/testcase1/MisspelledWordsBKTree.txt");
}

const std::vector<string> readDictionary(const string &filePath) {
    std::ifstream file(filePath);
    std::vector<string> dictionary;
    std::copy(std::istream_iterator<string>(file), std::istream_iterator<string>(), std::back_inserter(dictionary));
    file.close();
    return dictionary;
}

const int readMaxDistance(const string &filePath) {
    std::ifstream file(filePath);
    string line;
    std::getline(file, line);
    file.close();
    return std::stoi(line);
}

const std::vector<string> readSentence(const string &filePath) {
    std::ifstream file(filePath);
    string line;
    std::getline(file, line);
    std::stringstream ss(line);
    std::vector<string> words((std::istream_iterator<std::string>(ss)), std::istream_iterator<std::string>());
    file.close();
    return words;
}

void linearSearch(const std::vector<string> &dictionary, const int maxDistance, const std::vector<string> &words,
                  const string &resultFilePath) {
    clock_t t1, t2;
    t1 = clock();

    std::ofstream misspelledFile{resultFilePath};

    std::set<string> wordsAlreadyChecked;
    std::vector<string> misspelledWords;
    for (auto wordIter = words.begin(); wordIter != words.end(); wordIter++) {
        string word = *wordIter;
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (wordsAlreadyChecked.find(word) == wordsAlreadyChecked.end()) {
            wordsAlreadyChecked.insert(word);
            bool isInDict = false;
            for (auto dictIter = dictionary.begin(); dictIter != dictionary.end(); dictIter++) {
                if (word == *dictIter) {
                    isInDict = true;
                    break;
                }
            }
            if (!isInDict)
                misspelledWords.push_back(word);
        }
    }

    for (auto wordIter = misspelledWords.begin(); wordIter != misspelledWords.end(); wordIter++) {
        clock_t word_t1 = clock();
        std::vector<string> suggestions;
        for (auto dictIter = dictionary.begin(); dictIter != dictionary.end(); dictIter++) {
            int distance = Levenshtein::measureDistance(*wordIter, *dictIter);
            if (distance <= maxDistance)
                suggestions.push_back(*dictIter);
        }
        clock_t word_t2 = clock();
        float word_diff((float) word_t2 - (float) word_t1);
        cout << *wordIter << ": " << word_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl;

        misspelledFile << *wordIter << ":";
        for (auto suggestionsIter = suggestions.begin(); suggestionsIter != suggestions.end(); suggestionsIter++) {
            misspelledFile << *suggestionsIter;
            if (suggestionsIter + 1 != suggestions.end())
                misspelledFile << ", ";
        }
        misspelledFile << endl;
    }

    if (misspelledWords.size() == 0)
        misspelledFile << 0 << endl;

    misspelledFile.close();

    t2 = clock();
    float diff((float) t2 - (float) t1);
    cout << "Linear search running time: " << diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl << endl;
}

void bkTreeSearch(const BKTree &bkTree, const int maxDistance, const std::vector<string> &words,
                  const string &resultFilePath) {
    clock_t t1, t2;
    t1 = clock();

    std::ofstream misspelledFile{resultFilePath};
    int count = 0;

    std::set<string> wordsAlreadyChecked;
    for (auto wordIter = words.begin(); wordIter != words.end(); wordIter++) {
        string word = *wordIter;
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        bool isInDict = false;
        if (wordsAlreadyChecked.find(word) == wordsAlreadyChecked.end()) {
            wordsAlreadyChecked.insert(word);
            clock_t word_t1 = clock();
            std::vector<string> suggestions = bkTree.getSuggestedWords(word, maxDistance, isInDict);
            if (!isInDict) {
                clock_t word_t2 = clock();
                float word_diff((float) word_t2 - (float) word_t1);
                cout << word << ": " << word_diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl;
            }

            if (!isInDict) {
                count++;
                misspelledFile << *wordIter << ":";
                for (auto suggestionsIter = suggestions.begin();
                     suggestionsIter != suggestions.end(); suggestionsIter++) {
                    misspelledFile << *suggestionsIter;
                    if (suggestionsIter + 1 != suggestions.end())
                        misspelledFile << ", ";
                }
                misspelledFile << endl;
            }
        }
    }

    if (count == 0)
        misspelledFile << count;

    misspelledFile.close();

    t2 = clock();
    float diff((float) t2 - (float) t1);
    cout << "BK-trees running time: " << diff / (CLOCKS_PER_SEC / 1000) << "ms" << endl << endl;
}

const BKTree buildBKTree(const std::vector<string> &dictionary) {
    BKTree bkTree;
    for (auto iterator = dictionary.begin(); iterator != dictionary.end(); iterator++) {
        bkTree.addNode(*iterator);
    }
    return bkTree;
}