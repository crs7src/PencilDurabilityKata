# PencilDurabilityKata
A project based on these instructions: https://github.com/PillarTechnology/kata-pencil-durability

# To run
It was created in C++ and uses cmake to build so cmake needs to be installed before it can be built instructions are here: https://cmake.org/install/.
To run the tests with cmake installed change directory to /PencilDurabilityKata then run:
mkdir build
cd build
cmake ..
cd tests/basic_tests
make
./PencilTests

All the tests will run and the output will be displayed.

If you have clion the process is much simpler, all you have to do is open the project with clion and then go to tests/basic_tests/pencil_tests.cpp. The tests can be run from there by clicking on the tests and hitting shift+ctrl+F10 or just hitting the green circle next to the line of the test.