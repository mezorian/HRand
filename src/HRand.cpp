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
      initialValue(initialValue_) {


    if (minValue_ > maxValue_) {
        throw std::invalid_argument( "Error : minValue_ has to be <= maxValue_ . Please switch the order of the parameters." );
    }

    if (minDelta_ > maxDelta_) {
        throw std::invalid_argument( "Error : minDelta_ has to be <= maxDelta_ . Please switch the order of the parameters." );
    }

    long double diffDelta = static_cast<long double>(maxDelta_) - static_cast<long double>(minDelta_);
    long double diffValue = static_cast<long double>(maxValue_) - static_cast<long double>(minValue_);

    if (diffDelta > diffValue) {
        throw std::invalid_argument( "Error : (maxDelta_ - minDelta_) > (maxValue_ - minValue_) . Please select a smaller range for the delta paramters or a bigger range for the value parameters." );
    }

    if ( (initialValue_ > maxValue_) || (initialValue_ < minValue_) ) {
        throw std::invalid_argument( "Error : initialValue_ has to be <= maxValue_ and >= minValue_ . Please select a value within the valid range." );
    }


}

double HRand::getNewValue() {
    return initialValue;
}
