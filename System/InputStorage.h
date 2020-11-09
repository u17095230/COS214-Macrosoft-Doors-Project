//
// Created by Alexander Schmid on 2020/11/08.
//

#ifndef FORMULAONETEAM_INPUTSTORAGE_H
#define FORMULAONETEAM_INPUTSTORAGE_H
#include<string>

using namespace std;

class InputStorage {
private:
    int numPitstops;
    string* array;

    int degradeLaps;
    string* degradation;


    int numPitstopsWet;
    string* wetArray;
    int degradeLapsWet;
    string* degradationWet;

    int numPitstopsVeryWet;
    string* veryWetArray;
    int degradeLapsVeryWet;
    string* degradationVeryWet;

public:
    InputStorage();

    InputStorage(int numPitstops, string *array, int degradeLaps, string *degradation, int numPitstopsWet,
                 string *wetArray, int degradeLapsWet, string *degradationWet, int numPitstopsVeryWet,
                 string *veryWetArray, int degradeLapsVeryWet, string *degradationVeryWet);

    int getNumPitstops() const;

    void setNumPitstops(int numPitstops);

    string *getArray() const;

    void setArray(string *array);

    int getDegradeLaps() const;

    void setDegradeLaps(int degradeLaps);

    string *getDegradation() const;

    void setDegradation(string *degradation);

    int getNumPitstopsWet() const;

    void setNumPitstopsWet(int numPitstopsWet);

    string *getWetArray() const;

    void setWetArray(string *wetArray);

    int getDegradeLapsWet() const;

    void setDegradeLapsWet(int degradeLapsWet);

    string *getDegradationWet() const;

    void setDegradationWet(string *degradationWet);

    int getNumPitstopsVeryWet() const;

    void setNumPitstopsVeryWet(int numPitstopsVeryWet);

    string *getVeryWetArray() const;

    void setVeryWetArray(string *veryWetArray);

    int getDegradeLapsVeryWet() const;

    void setDegradeLapsVeryWet(int degradeLapsVeryWet);

    string *getDegradationVeryWet() const;

    void setDegradationVeryWet(string *degradationVeryWet);


};


#endif //FORMULAONETEAM_INPUTSTORAGE_H
