include_directories(C:/Libraries/googletest-master/googletest/include C:/Libraries/googletest-master/googletest)
add_executable(PencilTests
        pencil_tests.cpp ../../Pencil.cpp ../../Pencil.h)

target_link_libraries(PencilTests gtest gtest_main)
#target_link_libraries(PencilTests gtest PencilDurabilityKata)