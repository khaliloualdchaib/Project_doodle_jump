SET(CMAKE_CXX_STANDARD 14)
ADD_EXECUTABLE(
        doodlejump
        main.cpp

        logic_library/include/random.h
        logic_library/src/random.cpp

        logic_library/include/stopwatch.h
        logic_library/src/stopwatch.cpp


        logic_library/include/stopwatch.h logic_library/src/stopwatch.cpp)
target_link_libraries(doodlejump sfml-graphics sfml-window sfml-system)
INSTALL(TARGETS doodlejump DESTINATION ${PROJECT_SOURCE_DIR}/bin)