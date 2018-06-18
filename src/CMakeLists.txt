cmake_minimum_required(VERSION 3.8)

project(Masonry)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

set(SOURCES main.cpp mainWindow.cpp elemUI/masonryWidget.cpp elemUI/masonryItem.cpp lib/container.cpp lib/item.cpp)

set(HEADERS mainWindow.h elemUI/masonryWidget.h elemUI/masonryItem.h lib/container.h lib/item.h)

# Tell CMake to create the project executable
add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${HEADERS})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets  ${QT_QTMAIN_LIBRARY})
