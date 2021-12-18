SET(CMAKE_CXX_STANDARD 14)
ADD_EXECUTABLE(
        doodlejump
        main.cpp

        logic_library/include/random.h
        logic_library/src/random.cpp

        logic_library/include/stopwatch.h
        logic_library/src/stopwatch.cpp

        SFML_graphics_library/include/game.h
        SFML_graphics_library/src/game.cpp

        logic_library/include/world.h
        logic_library/src/world.cpp

        logic_library/include/observer_pattern/observable.h
        logic_library/include/observer_pattern/observer.h
        logic_library/src/observer_pattern/observable.cpp

        logic_library/include/abstractFactory.h

        logic_library/include/camera.h
        logic_library/src/camera.cpp

        SFML_graphics_library/include/SFMLplayer.h
        SFML_graphics_library/src/SFMLplayer.cpp

        logic_library/include/player.h
        logic_library/src/player.cpp

        SFML_graphics_library/include/SFMLentity.h
        SFML_graphics_library/src/SFMLentity.cpp

        logic_library/include/entity.h
        logic_library/src/entity.cpp

        logic_library/include/platforms/staticPlatform.h
        logic_library/src/platforms/staticPlatform.cpp

        SFML_graphics_library/include/platforms/SFMLstaticPlatform.h
        SFML_graphics_library/src/platforms/SFMLstaticPlatform.cpp
)
target_link_libraries(doodlejump sfml-graphics sfml-window sfml-system)
INSTALL(TARGETS doodlejump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
