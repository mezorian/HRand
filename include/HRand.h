/**
 * HistoryBasedRandomValue.h
 * Purpose: defines class HistoryBasedRandomValue
 *
 * @author mezorian
 * @version 1.1.0
 */

#ifndef HistoryBasedRandomValue_H
#define HistoryBasedRandomValue_H

/**
 * HistoryBasedRandomValue class
 * @brief HistoryBasedRandomValue generates history based random values
 *
 */
class HistoryBasedRandomValue {
    public:
        /* --- constructors / destructors --- */
        HistoryBasedRandomValue(double minValue_, double maxValue_, double minDelta_,
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
};

#endif // HistoryBasedRandomValue_H

