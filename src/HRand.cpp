/**
 * HRand.cpp
 * Purpose: implements class HRand
 *
 * @author mezorian
 * @version 1.1.0
 */


#include "HRand.h"

HRand::HRand(double minValue_, double maxValue_, double minDelta_, double maxDelta_, double initialValue_)
    : minValue(minValue_),
      maxValue(maxValue_),
      minDelta(minDelta_),
      maxDelta(maxDelta_),
      initialValue(initialValue_),
      firstValueUsed(false) {


    if (minValue_ > maxValue_) {
        throw std::invalid_argument( "Error : minValue_ has to be <= maxValue_ . Please switch the order of the parameters." );
    }

    if (minDelta_ > maxDelta_) {
        throw std::invalid_argument( "Error : minDelta_ has to be <= maxDelta_ . Please switch the order of the parameters." );
    }

    if ( (initialValue_ > maxValue_) || (initialValue_ < minValue_) ) {
        throw std::invalid_argument( "Error : initialValue_ has to be <= maxValue_ and >= minValue_ . Please select a value within the valid range." );
    }

    randomNumberGenerator = new std::mt19937_64(seed);
    unif = new std::uniform_real_distribution<double>(minDelta_,maxDelta_);
}

double HRand::getNewValue() {
    if (! firstValueUsed) {
        value = initialValue;
        firstValueUsed = true;
    } else {

        for (int i=0; i<5; i++) {
            long double nextValue = static_cast<long double>(value);
            nextValue += static_cast<long double>( (*unif)(*randomNumberGenerator) );
            if ( (nextValue >= static_cast<long double>(minValue)) && (nextValue <= static_cast<long double>(maxValue)) ) {
                value = static_cast<double>(nextValue);
                break;
            }
        }
    }

    return value;
}
