/**
 * HRand.cpp
 * Purpose: implements class HRand
 *
 * @author mezorian
 * @version 1.1.0
 */


#include "HRand.h"

/**
 * HRand::HRand
 * @brief Constructor of class HRand
 * @param minValue_ minimal possible random value which can be generated
 * @param maxValue_ maximal possible random value which can be generated
 * @param minDelta_ minimal possible change from the previous value to the next value
 * @param maxDelta_ maximal possible change from the previous value to the next value
 * @param initialValue_ very first initial value before any random value generation
 *
 * NOTE : This constructor function throws a std::invalid_argument exception if the parameters are
 *        not applying the following rules:
 *          minValue_ <= maxValue_
 *          minDelta_ <= maxDelta_
 *          initialValue_ <= maxValue_
 *          initialValue_ >= minValue_
 *
 */
HRand::HRand(double minValue_, double maxValue_, double minDelta_, double maxDelta_, double initialValue_)
    : minValue(minValue_),
      maxValue(maxValue_),
      minDelta(minDelta_),
      maxDelta(maxDelta_),
      initialValue(initialValue_),
      firstValueUsed(false) {

    // check if parameters are valid, otherwise throw execption
    checkParameters(minValue_, maxValue_, minDelta_, maxDelta_, initialValue_);

    // initialize random number generator and setup distributions
    randomNumberGenerator = new std::mt19937_64(seed);
    initialValueDistribution = new std::uniform_real_distribution<double>(minValue_,maxValue_);
    deltaDistribution = new std::uniform_real_distribution<double>(minDelta_,maxDelta_);

}

/**
 * HRand::HRand
 * @brief Constructor of class HRand
 * @param minValue_ minimal possible random value which can be generated
 * @param maxValue_ maximal possible random value which can be generated
 * @param minDelta_ minimal possible change from the previous value to the next value
 * @param maxDelta_ maximal possible change from the previous value to the next value
 *
 * NOTE : This constructor function throws a std::invalid_argument exception if the parameters are
 *        not applying the following rules:
 *          minValue_ <= maxValue_
 *          minDelta_ <= maxDelta_
 *
 */
HRand::HRand(double minValue_, double maxValue_, double minDelta_, double maxDelta_)
    : minValue(minValue_),
      maxValue(maxValue_),
      minDelta(minDelta_),
      maxDelta(maxDelta_),
      firstValueUsed(true) {

    // check if parameters are valid, otherwise throw execption
    checkParameters(minValue_, maxValue_, minDelta_, maxDelta_);

    // initialize random number generator
    randomNumberGenerator = new std::mt19937_64(seed);
    initialValueDistribution = new std::uniform_real_distribution<double>(minValue_,maxValue_);
    deltaDistribution = new std::uniform_real_distribution<double>(minDelta_,maxDelta_);

    // if it is not possible to generate a valid initial value use maxValue
    value = maxValue_;

    // try five times to generate a valid random value within the ranges of minValue and maxValue
    for (int i=0; i<5; i++) {

        double nextValue = (*initialValueDistribution)(*randomNumberGenerator);
        if ( (nextValue >= minValue) && (nextValue <= maxValue) ) {
            value = nextValue;
            break;
        }
    }
}

/**
 * HRand::getNewValue
 * @brief Generate a new random value within the range of minValue and maxValue
 * @return returns a new random value within the range of minValue and maxValue
 *
 * Generate a new random value within the range of minValue and maxValue.
 * If it is not possible to create a new random value after five tries the previous value
 * is selected as new random value.
 */
double HRand::getNewValue() {
    // if this function was called for the very first time and
    // if HRand was initialized with initial value
    // don't generate an random value, but use the initial value
    if (! firstValueUsed) {
        value = initialValue;
        firstValueUsed = true;

    // otherwise try to generate a new random value within the range of minValue and maxValue
    } else {

        for (int i=0; i<5; i++) {

            // generate a new random value based on the the previous value
            long double nextValue = static_cast<long double>(value);
            nextValue += static_cast<long double>( (*deltaDistribution)(*randomNumberGenerator) );

            // check whether the generate value is with the valid range
            // and either except it or try again
            if ( (nextValue >= static_cast<long double>(minValue)) && (nextValue <= static_cast<long double>(maxValue)) ) {
                value = static_cast<double>(nextValue);
                break;
            }
        }
    }

    // return the new random value
    return value;
}

/**
 * HRand::checkParameters
 * @brief checks if parameters are valid, otherwise it throws an exeception
 * @param minValue_ minimal possible random value which can be generated
 * @param maxValue_ maximal possible random value which can be generated
 * @param minDelta_ minimal possible change from the previous value to the next value
 * @param maxDelta_ maximal possible change from the previous value to the next value
 *
 * NOTE : This check function throws a std::invalid_argument exception if the parameters are
 *        not applying the following rules:
 *          minValue_ <= maxValue_
 *          minDelta_ <= maxDelta_
 *
 */
void HRand::checkParameters(double minValue_, double maxValue_, double minDelta_, double maxDelta_) {
    if (minValue_ > maxValue_) {
        throw std::invalid_argument( "Error : minValue_ has to be <= maxValue_ . Please switch the order of the parameters." );
    }

    if (minDelta_ > maxDelta_) {
        throw std::invalid_argument( "Error : minDelta_ has to be <= maxDelta_ . Please switch the order of the parameters." );
    }
}

/**
 * HRand::checkParameters
 * @brief checks if parameters are valid, otherwise it throws an exeception
 * @param minValue_ minimal possible random value which can be generated
 * @param maxValue_ maximal possible random value which can be generated
 * @param minDelta_ minimal possible change from the previous value to the next value
 * @param maxDelta_ maximal possible change from the previous value to the next value
 * @param initialValue_ very first initial value before any random value generation
 *
 * NOTE : This check function throws a std::invalid_argument exception if the parameters are
 *        not applying the following rules:
 *          minValue_ <= maxValue_
 *          minDelta_ <= maxDelta_
 *          initialValue_ <= maxValue_
 *          initialValue_ >= minValue_
 *
 */
void HRand::checkParameters(double minValue_, double maxValue_, double minDelta_, double maxDelta_, double initialValue_) {
    checkParameters(minValue_, maxValue_, minDelta_, maxDelta_);

    if ( (initialValue_ > maxValue_) || (initialValue_ < minValue_) ) {
        throw std::invalid_argument( "Error : initialValue_ has to be <= maxValue_ and >= minValue_ . Please select a value within the valid range." );
    }

}
