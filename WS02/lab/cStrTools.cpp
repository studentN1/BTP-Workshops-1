/* --------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Student Name: Layla Medina Perez
Student ID: 118404219
Student Email: lmedina-perez@myseneca.ca
Date of completion (MM/DD/YY): 01/17/2022
-----------------------------------------------------------*/
#include <iostream>
using namespace std;

namespace sdds {

    // Function definitions:
    // -----------------------------------------------------------

    // returns the lower case value of a character
    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
        return ch;
    }

    // compares s1 and s2 cStrings and returns:
    // > 0 if s1 > s2
    // < 0 if s1 < s3
    // == 0 if s1 == s2
    int strCmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

    // compares s1 and s2 cStrings upto len characters and returns:
    // > 0 if s1 > s2
    // < 0 if s1 < s3
    // == 0 if s1 == s2
    int strnCmp(const char* s1, const char* s2, int len) {
        int i = 0;
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
            i++;
        }
        return s1[i] - s2[i];
    }

    // copies src to des
    void strCpy(char* des, const char* src) {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = 0;
    }

    // returns the length of str
    int strLen(const char* str) {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    // if "find" is found in "str" it will return the addres of the match
    // if not found it will returns nullptr (zero)
    const char* strStr(const char* str, const char* find) {
        const char* faddress = nullptr;
        int i, flen = strLen(find), slen = strLen(str);
        for (i = 0; i <= slen - flen && strnCmp(&str[i], find, flen); i++);
        if (i <= slen - flen) faddress = &str[i];
        return faddress;
    }

    // returns true if ch is alphabetical
    int isAlpha(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    // returns true if ch is a whitespace character
    int isSpace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    // removes the non-alphabetic characters from the begining and end of a word
    void trim(char word[]) {
        int i;
        while (word[0] && !isAlpha(word[0])) {
            strCpy(word, word + 1);
        }
        i = strLen(word);
        while (i && !isAlpha(word[i - 1])) {
            word[i-- - 1] = 0;
        }
    }

    // copies the  lower case version of the source into des.
    void toLowerCaseAndCopy(char des[], const char source[]) {
        int i = 0, j = 0;
        for (; source[i] != 0; i++) {
            des[j++] = toLower(source[i]);
        }
        des[j] = 0;
    }

    // reads a cString upto maxSize characters or upto the delimiter character,
    // whichever comes first (skipping leading white space characters but accpting
    // spaces in the cString)
    void read(char* cString, unsigned int maxSize, char delimiter) {
        cout << "Hello i am in cStrTools.read() START" << endl;///////////////////////////////////////
        char ch = 0;
        unsigned int i = 0;
        //delimiter = '\n';
        cout << "delim = " << delimiter << endl;///////////////////////////////////////

        // skipping leading white space chars
        do {
            cin.get(ch); // reads one character from input
        } while (isSpace(ch));
        // read char by char util hitting delimiter or maxSize
        cout << "Hello i am in cStrTools.read() mid" << endl;///////////////////////////////////////

        for (i = 0; i < maxSize && ch != delimiter; i++) {
            cString[i] = ch;
            // read the cString stopping at the size limit
            if (i < maxSize - 1) cin.get(ch);
        }
        cString[i] = 0; // make sure the cString is null terminated
        cout << "Hello i am in cStrTools.read()" << endl;///////////////////////////////////////
    }
    // -----------------------------------------------------------
}