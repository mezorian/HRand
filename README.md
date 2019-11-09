# HRand - history based random
A c++ implementation to create a random value which at the next generation is slowly randomly changing

[![Build Status](https://travis-ci.org/open-pete/HRand.svg?branch=development)](https://travis-ci.org/open-pete/HRand) [![Coverage Status](https://coveralls.io/repos/github/open-pete/HRand/badge.svg?branch=development)](https://coveralls.io/github/open-pete/HRand?branch=development)

## What is this repository for?
Sometimes you need dummy data for your project which is not totally random, but which has a random initial value and then randomly increases or decreases. 
To easily create such values the HRand class can be used

## How to use

# Roadmap

## v1.0.0 Create single values which are randomly increasing and decreasing
- [ ] initialize randomly within a set range
- [ ] randomly increase or decrease within a set delta-range 
- [ ] don't exceed the total range
- [ ] don't exceed the delta range
- [ ] above requirements are tested
- [ ] ci working
- [ ] coverage working
