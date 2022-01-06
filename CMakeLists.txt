# min wersja cmake
cmake_minimum_required(VERSION 3.16.3)

# nazwa projektu i wersja
project(Template VERSION 1.0)

# dodanie pliku konfiguracyjnego projektu
configure_file(Include/Config.h.in Include/Config.h)

# wskazanie maina
add_executable(${PROJECT_NAME} Src/Main.cpp)

# automatyczne pobieranie i updatowanie wszelkich submodułów
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update failed with ${GIT_SUBMOD_RESULT}")
        endif()
    endif()
endif()

# dodanie podfolderów do projektu
add_subdirectory(Lib)
#add_subdirectory(external/glfw)

# wskazanie folderów "include"(plików nagłówkowych bibliotek) 
target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_BINARY_DIR}
    PUBLIC Lib 
#    PUBLIC external/glfw/include
)

# wskazanie folderów "src"(plików źródłowych bibliotek)
target_link_directories(${PROJECT_NAME}
    PRIVATE Lib
#    PRIVATE external/glfw/src
)

# linkowanie blibliotek
#target_link_libraries(${PROJECT_NAME} glfw)