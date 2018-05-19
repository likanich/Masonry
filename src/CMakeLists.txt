cmake_minimum_required(VERSION 2.8)

project(Masonry)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

set(SOURCES main.cpp mainwindow.cpp masonry.cpp)

set(HEADERS mainwindow.h masonry.h)

# Tell CMake to create the helloworld executable
add_executable(masonry ${SOURCES} ${HEADERS})

# Use the Widgets module from Qt 5.
target_link_libraries(masonry Qt5::Widgets)
