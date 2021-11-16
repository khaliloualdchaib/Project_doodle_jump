SET(SRC main.cpp)
ADD_EXECUTABLE(doodlejump ${SRC})
target_link_libraries(doodlejump sfml-graphics sfml-window sfml-system)
INSTALL(TARGETS doodlejump DESTINATION ${PROJECT_SOURCE_DIR}/bin)