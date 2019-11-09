/**
 * DummySensorTest.cpp
 * Purpose: implements tests for class Dummy Sensor
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "catch.hpp"
#include <iostream>

#include "Sensor.h"
#include "DummySensor.h"

TEST_CASE("test if DummySensor returns values in the previously defined range") {
    // randomize
    srand(time(NULL));

    Sensor Sensor1;
    int minValue=0, maxValue=0;
    string name="", dataSource="";

    SECTION("Test for temperature sensor") {
        minValue = -50;
        maxValue = 50;
        name = "Temperatur";
        dataSource = "Sensor";
    }

    SECTION("Test for air pressure sensor") {
        minValue = 0;
        maxValue = 1200;
        name = "AirPressure";
        dataSource = "Sensor";
    }

    SECTION("Test for speed sensor") {
        minValue = 0;
        maxValue = 1000;
        name = "Speed";
        dataSource = "Sensor";
    }

    SECTION("Test for direction sensor") {
        minValue = 0;
        maxValue = 360;
        name = "Direction";
        dataSource = "Sensor";
    }

    SECTION("Test for GPS sensor / sensor with more than one return value") {
        minValue = 0;
        maxValue = 360;
        name = "GPS";
        dataSource = "Sensor";
    }

    for (int i=0; i<100; i++) {
        // create dummy Sensor
        std::cout << "created " << name <<  " sensor " << endl;
        Sensor1.setSensorType(new DummySensor(minValue, maxValue, name, dataSource));

        // read value from dummy sensor
        DataBuffer result = Sensor1.readSensor();

        // check if value is in the expected range
        if (name == "GPS") {
            REQUIRE(result.data["GPS_Longitude"] >= static_cast<double>(minValue) );
            REQUIRE(result.data["GPS_Longitude"] <= static_cast<double>(maxValue) );
            REQUIRE(result.data["GPS_Latitude"] >= static_cast<double>(minValue) );
            REQUIRE(result.data["GPS_Latitude"] <= static_cast<double>(maxValue) );

        } else {
            REQUIRE(result.data[name] >= static_cast<double>(minValue) );
            REQUIRE(result.data[name] <= static_cast<double>(maxValue) );
        }

        std::cout << "DummySensor.read == " << result << endl;

        // check if startDateTime is the current UTC time
        DateTimePP dt;
        REQUIRE(result.startDateTime == dt.now(true));
    }

}
