/********************
* Author:Saibuu V.M *
*                   *
* Date: 29.09.2025  *
*                   *
********************/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main() {
    map<char, int> singleLetterFrequency;         
    map<string, int> doubleLetterCombinationCount;

    ifstream inputFile("text.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    string fullTextContent;
    string currentLine;
    while (getline(inputFile, currentLine)) {
        fullTextContent += currentLine + '\n';
    }
    inputFile.close();

    char previousCharacter = '\0';

    for (int characterIndex = 0; characterIndex < fullTextContent.size(); characterIndex++) {
        char currentCharacter = fullTextContent[characterIndex];

        if (isalpha(currentCharacter)) {
            singleLetterFrequency[currentCharacter]++;

            if (isalpha(previousCharacter)) {
                string twoLetterCombination = "";
                twoLetterCombination += previousCharacter;
                twoLetterCombination += currentCharacter;
                doubleLetterCombinationCount[twoLetterCombination]++;
            }

            previousCharacter = currentCharacter;
        } else {
            previousCharacter = '\0';
        }
    }

    cout << "Letter frequency:" << endl;
    for (auto letterIterator = singleLetterFrequency.begin(); 
         letterIterator != singleLetterFrequency.end(); 
         ++letterIterator) {
        cout << letterIterator->first << " : " << letterIterator->second << endl;
    }

    cout << "\nTwo-letter combination frequency:" << endl;
    for (auto pairIterator = doubleLetterCombinationCount.begin(); 
         pairIterator != doubleLetterCombinationCount.end(); 
         ++pairIterator) {
        cout << pairIterator->first << " : " << pairIterator->second << endl;
    }

    return 0;
}