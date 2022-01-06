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
        logic_library/include/platforms/platform.h logic_library/src/platforms/platform.cpp SFML_graphics_library/include/platforms/SFMLplatform.h SFML_graphics_library/src/platforms/SFMLplatform.cpp SFML_graphics_library/include/concreteFactory.h SFML_graphics_library/src/concreteFactory.cpp logic_library/include/platforms/temporaryPlatform.h logic_library/src/platforms/temporaryPlatform.cpp SFML_graphics_library/include/platforms/SFMLtemporaryPlatform.h SFML_graphics_library/src/platforms/SFMLtemporaryPlatform.cpp logic_library/include/platforms/horizontalPlatform.h logic_library/src/platforms/horizontalPlatform.cpp SFML_graphics_library/include/platforms/SFMLhorizontalPlatform.h SFML_graphics_library/src/platforms/SFMLhorizontalPlatform.cpp logic_library/include/platforms/verticalPlatform.h logic_library/src/platforms/verticalPlatform.cpp SFML_graphics_library/include/platforms/SFMLverticalPlatform.h SFML_graphics_library/src/platforms/SFMLverticalPlatform.cpp logic_library/include/bonus/bonus.h logic_library/src/bonus/bonus.cpp logic_library/include/bg_tile.h logic_library/src/bg_tile.cpp SFML_graphics_library/include/SFMLbg_tile.h SFML_graphics_library/src/SFMLbg_tile.cpp)
target_link_libraries(doodlejump sfml-graphics sfml-window sfml-system)
INSTALL(TARGETS doodlejump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
