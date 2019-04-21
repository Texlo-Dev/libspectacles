cmake_minimum_required(VERSION 3.14)
project(spectacles)

set(CMAKE_CXX_STANDARD 17)
include(cmake-modules/DownloadProject.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include(ExternalProject)
include(FindZLIB)

add_subdirectory(src)

download_project(
        PROJ amqpcpp
        GIT_REPOSITORY https://github.com/CopernicaMarketingSoftware/AMQP-CPP
)


add_subdirectory(
        ${amqpcpp_SOURCE_DIR}
        ${amqpcpp_BINARY_DIR}
)

find_package(ZLIB REQUIRED)
find_package(Threads REQUIRED)


install(TARGETS spectacles DESTINATION lib)