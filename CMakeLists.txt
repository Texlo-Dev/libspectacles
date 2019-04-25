cmake_minimum_required(VERSION 3.14)
project(spectacles)

set(CMAKE_CXX_STANDARD 11)
set(SPECTACLES_INCLUDE_DIR ${LIBSPECTACLES_INCLUDE_DIRS}/include)
include(cmake-modules/DownloadProject.cmake)
include_directories(${ZLIB_INCLUDE_DIRS})
include(ExternalProject)
include(FindZLIB)

find_library(UWS_FOUND uWS)
if (NOT UWS_FOUND)
    message(STATUS "Could NOT find UWS")
    ExternalProject_Add(
            uWS_ext

            GIT_REPOSITORY "https://github.com/uNetworking/uWebSockets.git"
            GIT_TAG "v0.14.5"

            CONFIGURE_COMMAND ""
            BUILD_COMMAND "make"
            BUILD_IN_SOURCE true
    )
endif (NOT UWS_FOUND)

find_library(RMQ_CLIENT_FOUND SimpleAmqpClient)
if (NOT RMQ_CLIENT_FOUND)
    message(STATUS "Could not find RabbitMQ client library.")
    ExternalProject_Add(
            SimpleAmqpClient_ext
            GIT_REPOSITORY https://github.com/alanxz/SimpleAmqpClient.git

            CMAKE_ARGS -DBUILD_EXAMPLES=OFF -DBUILD_STATIC_LIBS=OFF -DBUILD_TESTS=OFF -DBUILD_TOOLS=OFF -DBUILD_TOOLS_DOCS=OFF -DBUILD_API_DOCS=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    )
endif (NOT RMQ_CLIENT_FOUND)

add_library(spectacles SHARED src/gateway/Manager.cpp src/brokers/amqp.cpp src/brokers/consumer.cpp src/brokers/producer.cpp)

if (NOT RMQ_CLIENT_FOUND)
    add_dependencies(spectacles SimpleAmqpClient_ext)
endif (NOT RMQ_CLIENT_FOUND)

if (NOT UWS_FOUND)
    add_dependencies(spectacles uWS_ext)
endif (NOT UWS_FOUND)

find_package(ZLIB REQUIRED)
find_package(Threads REQUIRED)

target_link_libraries(spectacles uWS SimpleAmqpClient ${ZLIB_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS spectacles DESTINATION lib)
install(FILES include/spectacles.h DESTINATION include/spectacles)
install(DIRECTORY include/brokers include/gateway include/rest DESTINATION include/spectacles)