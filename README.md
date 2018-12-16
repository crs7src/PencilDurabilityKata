# PencilDurabilityKata
A project based on these instructions: https://github.com/PillarTechnology/kata-pencil-durability

## Prerequisite
It was created in C++ and uses cmake to build so cmake needs to be installed before it can be built. Installation instructions for cmake are here: https://cmake.org/install/.

## To run
```
mkdir build
cd build
cmake ..
cd tests/basic_tests
make
./PencilTests
```

All the tests will run and the output will be displayed.

If you use the clion IDE the process is much simpler. Open the project with clion, then open tests/basic_tests/pencil_tests.cpp. The tests can be run from there by clicking on the tests and hitting shift+ctrl+F10 or just hitting the green circle next to the line of the test.
