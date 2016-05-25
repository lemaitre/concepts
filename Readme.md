# C++ Concepts

This repository is a test to provide a basic implementation of concepts that should be in the standard.

## Files
- `concepts.h`: header containing concepts that should be in the standard (in the sense that these concepts may be added in the standard when it will integrate concepts).
- `test.cpp`: test the implementation of concepts

## Concepts
All implemented concepts are referenced here: [Concepts.md](Concepts.md)

## Compilation
Compilation needs GCC 6.1 or higher with the following command line:
`g++ -std=c++1z -fconcepts test.cpp -o test`

## Disclaimer
- The interface of the concepts is defined as a guess of how it will be in the standard (C++20?)
- This is just a toy and has absolutely no warranty of any kind.
