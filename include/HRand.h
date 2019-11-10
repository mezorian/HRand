/**
 * HRand.h
 * Purpose: defines class HRand
 *
 * @author mezorian
 * @version 1.1.0
 */

#ifndef HRand_H
#define HRand_H

#include <stdexcept>
#include <random>
#include <ctime>
#include <functional>

/**
 * HRand class
 * @brief HRand generates history based random values
 *
 */
class HRand {
    public:
        /* --- constructors / destructors --- */
        HRand(double minValue_, double maxValue_, double minDelta_,
                                double maxDelta_, double initialValue_ = 0.0);

        /* --- random value generation --- */
        double getNewValue();

    private:
        double value;
        double minValue;
        double maxValue;
        double minDelta;
        double maxDelta;
        double initialValue;
        bool firstValueUsed;

        const unsigned int seed = time(NULL);
        std::mt19937_64 *randomNumberGenerator;
        std::uniform_real_distribution<double> *unif;
};

#endif // HRand_H

