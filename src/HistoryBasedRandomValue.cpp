/**
 * HistoryBasedRandomValue.cpp
 * Purpose: implements class HistoryBasedRandomValue
 *
 * @author mezorian
 * @version 1.1.0
 */


#include "HistoryBasedRandomValue.h"

#ifdef DUMMY_VALUES

HistoryBasedRandomValue::HistoryBasedRandomValue(double minValue_, double maxValue_, double minDelta_, double maxDelta_, double initialValue_)
    : minValue(minValue_),
      maxValue(maxValue_),
      minDelta(minDelta_),
      maxDelta(maxDelta_),
      initialValue(initialValue_) {


}

#endif DUMMY_VALUES
