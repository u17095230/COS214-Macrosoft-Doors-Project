//
// Created by Alexander Schmid on 2020/11/08.
//

#include "InputStorage.h"

InputStorage::InputStorage(int numPitstops, string *array, int degradeLaps, string *degradation, int numPitstopsWet,
                           string *wetArray, int degradeLapsWet, string *degradationWet, int numPitstopsVeryWet,
                           string *veryWetArray, int degradeLapsVeryWet, string *degradationVeryWet): numPitstops(numPitstops),
                           array(array), degradeLaps(degradeLaps), degradation(degradation), numPitstopsWet(numPitstopsWet),
                           wetArray(wetArray),degradeLapsWet(degradeLapsWet),degradationWet(degradationWet),numPitstopsVeryWet(numPitstopsVeryWet),
                           veryWetArray(veryWetArray),degradeLapsVeryWet(degradeLapsVeryWet),degradationVeryWet(degradationVeryWet) {}

int InputStorage::getNumPitstops() const {
    return numPitstops;
}

void InputStorage::setNumPitstops(int numPitstops) {
    InputStorage::numPitstops = numPitstops;
}

string *InputStorage::getArray() const {
    return array;
}

void InputStorage::setArray(string *array) {
    InputStorage::array = array;
}

int InputStorage::getDegradeLaps() const {
    return degradeLaps;
}

void InputStorage::setDegradeLaps(int degradeLaps) {
    InputStorage::degradeLaps = degradeLaps;
}

string *InputStorage::getDegradation() const {
    return degradation;
}

void InputStorage::setDegradation(string *degradation) {
    InputStorage::degradation = degradation;
}

int InputStorage::getNumPitstopsWet() const {
    return numPitstopsWet;
}

void InputStorage::setNumPitstopsWet(int numPitstopsWet) {
    InputStorage::numPitstopsWet = numPitstopsWet;
}

string *InputStorage::getWetArray() const {
    return wetArray;
}

void InputStorage::setWetArray(string *wetArray) {
    InputStorage::wetArray = wetArray;
}

int InputStorage::getDegradeLapsWet() const {
    return degradeLapsWet;
}

void InputStorage::setDegradeLapsWet(int degradeLapsWet) {
    InputStorage::degradeLapsWet = degradeLapsWet;
}

string *InputStorage::getDegradationWet() const {
    return degradationWet;
}

void InputStorage::setDegradationWet(string *degradationWet) {
    InputStorage::degradationWet = degradationWet;
}

int InputStorage::getNumPitstopsVeryWet() const {
    return numPitstopsVeryWet;
}

void InputStorage::setNumPitstopsVeryWet(int numPitstopsVeryWet) {
    InputStorage::numPitstopsVeryWet = numPitstopsVeryWet;
}

string *InputStorage::getVeryWetArray() const {
    return veryWetArray;
}

void InputStorage::setVeryWetArray(string *veryWetArray) {
    InputStorage::veryWetArray = veryWetArray;
}

int InputStorage::getDegradeLapsVeryWet() const {
    return degradeLapsVeryWet;
}

void InputStorage::setDegradeLapsVeryWet(int degradeLapsVeryWet) {
    InputStorage::degradeLapsVeryWet = degradeLapsVeryWet;
}

string *InputStorage::getDegradationVeryWet() const {
    return degradationVeryWet;
}

void InputStorage::setDegradationVeryWet(string *degradationVeryWet) {
    InputStorage::degradationVeryWet = degradationVeryWet;
}
