/**
 * HRandTest.cpp
 * Purpose: implements tests for class HRand
 *
 * @author mezorian
 * @version 1.0.0
 */

#include <cfloat>

#include "catch.hpp"
#include "HRand.h"

TEST_CASE("Test if HRand throws exceptions at initialization only for wrong arguments, otherwise not") {
    double min=0.0, max=0.0, minDelta=0.0, maxDelta=0.0, initialValue=0.0;
    bool willThrowException = false;

    SECTION("min > max") {
        min=1.0001;
        max=1.0000;
        minDelta=0.0;
        maxDelta=0.0;
        initialValue=1.0001;
        willThrowException = true;
    }

    SECTION("min < max") {
        min=1.0000;
        max=1.0001;
        minDelta=0.0;
        maxDelta=0.0;
        initialValue=1.0001;
        willThrowException = false;
    }

    SECTION("min == max") {
        min=1.0001;
        max=1.0001;
        minDelta=0.0;
        maxDelta=0.0;
        initialValue=1.0001;
        willThrowException = false;
    }

    SECTION("minDelta > maxDelta") {
        min=-100;
        max=10000;
        minDelta=1.0001;
        maxDelta=1.0000;
        initialValue=0.0;
        willThrowException = true;
    }

    SECTION("minDelta < maxDelta") {
        min=-100;
        max=10000;
        minDelta=1.0000;
        maxDelta=1.0001;
        initialValue=0.0;
        willThrowException = false;
    }

    SECTION("minDelta == maxDelta") {
        min=-100;
        max=10000;
        minDelta=1.0001;
        maxDelta=1.0001;
        initialValue=0.0;
        willThrowException = false;
    }

    SECTION("initialValue > max") {
        min=-100;
        max=10000;
        minDelta=1.0000;
        maxDelta=1.0001;
        initialValue=10000.1;
        willThrowException = true;
    }

    SECTION("initialValue == max") {
        min=-100;
        max=10000;
        minDelta=1.0000;
        maxDelta=1.0001;
        initialValue=10000;
        willThrowException = false;
    }

    SECTION("initialValue < max") {
        min=-100;
        max=10000;
        minDelta=1.0000;
        maxDelta=1.0001;
        initialValue=9999.999;
        willThrowException = false;
    }

    SECTION("initialValue < min") {
        min=-100;
        max=10000;
        minDelta=1.0000;
        maxDelta=1.0001;
        initialValue=-100.0001;
        willThrowException = true;
    }

    SECTION("initialValue == min") {
        min=-100;
        max=10000;
        minDelta=1.0000;
        maxDelta=1.0001;
        initialValue=-100;
        willThrowException = false;
    }

    SECTION("initialValue > min") {
        min=-100;
        max=10000;
        minDelta=1.0000;
        maxDelta=1.0001;
        initialValue=-99.9999;
        willThrowException = false;
    }

    HRand* value;
    if (willThrowException) {
        REQUIRE_THROWS(value = new HRand(min,max,minDelta,maxDelta,initialValue));
    } else {
        REQUIRE_NOTHROW(value = new HRand(min,max,minDelta,maxDelta,initialValue));
    }
}


TEST_CASE("Test if HRand works if initialized with initialValue set") {

    double min=0.0, max=0.0, minDelta=0.0, maxDelta=0.0, initialValue=0.0;

    SECTION("all values are 0.0") {
        min=0.0;
        max=0.0;
        minDelta=0.0;
        maxDelta=0.0;
        initialValue=0.0;
    }

    SECTION("small positive and negative values") {
        min=-10.0;
        max=10.0;
        minDelta=-1.0;
        maxDelta=1.0;
        initialValue=2.0;
    }

    SECTION("all values are DBL_MAX") {
        min=DBL_MAX;
        max=DBL_MAX;
        minDelta=DBL_MAX;
        maxDelta=DBL_MAX;
        initialValue=DBL_MAX;
    }

    SECTION("all values are DBL_MIN") {
        min=DBL_MIN;
        max=DBL_MIN;
        minDelta=DBL_MIN;
        maxDelta=DBL_MIN;
        initialValue=DBL_MIN;
    }

    SECTION("min values are DBL_MIN, max values are DBL_MAX, initial value is DBL_MIN") {
        min=DBL_MIN;
        max=DBL_MAX;
        minDelta=DBL_MIN;
        maxDelta=DBL_MAX;
        initialValue=DBL_MIN;
    }

    SECTION("min values are DBL_MIN, max values are DBL_MAX, initial value is DBL_MAX") {
        min=DBL_MIN;
        max=DBL_MAX;
        minDelta=DBL_MIN;
        maxDelta=DBL_MAX;
        initialValue=DBL_MAX;
    }

    SECTION("normal positive values") {
        min=15.678;
        max=22.333;
        minDelta=1.01;
        maxDelta=2.522;
        initialValue=20.001;
    }

    SECTION("normal negative values") {
        min=-333.222;
        max=-234.33;
        minDelta=-21.5222;
        maxDelta=-12.01;
        initialValue=-235.1001;
    }

    SECTION("big positive values") {
        min=15234234.678;
        max=244444221.333;
        minDelta=12222.01;
        maxDelta=233333.522;
        initialValue=22232323.001;
    }

    SECTION("big negative values") {
        min=-3336666666.222;
        max=-234234234.33;
        minDelta=-214667.5222;
        maxDelta=-122342.01;
        initialValue=-234299934.34;
    }

    SECTION("small positive values") {
        min=0.00678;
        max=0.03330;
        minDelta=0.000001;
        maxDelta=0.000522;
        initialValue=0.00800;
    }

    SECTION("small negative values") {
        min=-0.000222;
        max=-0.000033;
        minDelta=-0.000022;
        maxDelta=-0.000001;
        initialValue=-0.000221;
    }

    SECTION("all values equal negative") {
        min=-1444.1234;
        max=-1444.1234;
        minDelta=-1444.1234;
        maxDelta=-1444.1234;
        initialValue=-1444.1234;
    }

    SECTION("all values equal positive") {
        min=745646.234;
        max=745646.234;
        minDelta=745646.234;
        maxDelta=745646.234;
        initialValue=745646.234;
    }

    HRand value(min,max,minDelta,maxDelta,initialValue);

    // check if initial value is the expected one
    REQUIRE(value.getNewValue() == initialValue);

    double previousValue = initialValue;

    for (int i=0; i < 100; i++) {
        double hRandValue = value.getNewValue();
        REQUIRE(hRandValue >= min);
        REQUIRE(hRandValue <= max);
        if (hRandValue != previousValue) {
            REQUIRE(static_cast<long double>(hRandValue) >= static_cast<long double>(previousValue) + static_cast<long double>(minDelta));
            REQUIRE(static_cast<long double>(hRandValue) <= static_cast<long double>(previousValue) + static_cast<long double>(maxDelta));
        }
        previousValue = hRandValue;
    }
}


TEST_CASE("Test if HRand works if initialized without initialValue set") {

    double min=0.0, max=0.0, minDelta=0.0, maxDelta=0.0;

    SECTION("all values are 0.0") {
        min=0.0;
        max=0.0;
        minDelta=0.0;
        maxDelta=0.0;
    }

    SECTION("small positive and negative values") {
        min=-10.0;
        max=10.0;
        minDelta=-1.0;
        maxDelta=1.0;
    }

    SECTION("all values are DBL_MAX") {
        min=DBL_MAX;
        max=DBL_MAX;
        minDelta=DBL_MAX;
        maxDelta=DBL_MAX;
    }

    SECTION("all values are DBL_MIN") {
        min=DBL_MIN;
        max=DBL_MIN;
        minDelta=DBL_MIN;
        maxDelta=DBL_MIN;
    }

    SECTION("min values are DBL_MIN, max values are DBL_MAX, initial value is DBL_MIN") {
        min=DBL_MIN;
        max=DBL_MAX;
        minDelta=DBL_MIN;
        maxDelta=DBL_MAX;
    }

    SECTION("min values are DBL_MIN, max values are DBL_MAX, initial value is DBL_MAX") {
        min=DBL_MIN;
        max=DBL_MAX;
        minDelta=DBL_MIN;
        maxDelta=DBL_MAX;
    }

    SECTION("normal positive values") {
        min=15.678;
        max=22.333;
        minDelta=1.01;
        maxDelta=2.522;
    }

    SECTION("normal negative values") {
        min=-333.222;
        max=-234.33;
        minDelta=-21.5222;
        maxDelta=-12.01;
    }

    SECTION("big positive values") {
        min=15234234.678;
        max=244444221.333;
        minDelta=12222.01;
        maxDelta=233333.522;
    }

    SECTION("big negative values") {
        min=-3336666666.222;
        max=-234234234.33;
        minDelta=-214667.5222;
        maxDelta=-122342.01;
    }

    SECTION("small positive values") {
        min=0.00678;
        max=0.03330;
        minDelta=0.000001;
        maxDelta=0.000522;
    }

    SECTION("small negative values") {
        min=-0.000222;
        max=-0.000033;
        minDelta=-0.000022;
        maxDelta=-0.000001;
    }

    SECTION("all values equal negative") {
        min=-1444.1234;
        max=-1444.1234;
        minDelta=-1444.1234;
        maxDelta=-1444.1234;
    }

    SECTION("all values equal positive") {
        min=745646.234;
        max=745646.234;
        minDelta=745646.234;
        maxDelta=745646.234;
    }

    HRand value(min,max,minDelta,maxDelta);

    // check if initial value is the expected one

    double previousValue = 0;

    for (int i=0; i < 100; i++) {
        double hRandValue = value.getNewValue();
        REQUIRE(hRandValue >= min);
        REQUIRE(hRandValue <= max);
        if ( (i != 0) && (hRandValue != previousValue) ) {
            REQUIRE(static_cast<long double>(hRandValue) >= static_cast<long double>(previousValue) + static_cast<long double>(minDelta));
            REQUIRE(static_cast<long double>(hRandValue) <= static_cast<long double>(previousValue) + static_cast<long double>(maxDelta));
        }
        previousValue = hRandValue;
    }
}

TEST_CASE("Test if getNewValue returns the previous value if it cannot generate a valid number within some tries") {
    double min=0.0, max=0.0, minDelta=0.0, maxDelta=0.0, initialValue=0.0;

    SECTION("all values are 0.0") {
        min=0.0;
        max=0.0;
        minDelta=0.0;
        maxDelta=0.0;
        initialValue=0.0;
    }

    SECTION("all values are DBL_MAX") {
        min=DBL_MAX;
        max=DBL_MAX;
        minDelta=DBL_MAX;
        maxDelta=DBL_MAX;
        initialValue=DBL_MAX;
    }

    SECTION("all values are DBL_MIN") {
        min=DBL_MIN;
        max=DBL_MIN;
        minDelta=DBL_MIN;
        maxDelta=DBL_MIN;
        initialValue=DBL_MIN;
    }

    SECTION("all values equal negative") {
        min=-1444.1234;
        max=-1444.1234;
        minDelta=-1444.1234;
        maxDelta=-1444.1234;
        initialValue=-1444.1234;
    }

    SECTION("all values equal positive") {
        min=745646.234;
        max=745646.234;
        minDelta=745646.234;
        maxDelta=745646.234;
        initialValue=745646.234;
    }

    HRand value(min,max,minDelta,maxDelta,initialValue);

    // check if initial value is the expected one
    REQUIRE(value.getNewValue() == initialValue);

    double previousValue = initialValue;

    for (int i=0; i < 100; i++) {
        double hRandValue = value.getNewValue();
        REQUIRE(value.getNewValue() == previousValue);
        previousValue = hRandValue;
    }
}


