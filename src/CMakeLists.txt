add_library(spectacles SHARED brokers/AmqpBroker.cpp gateway/Shard.cpp gateway/Manager.cpp brokers/Broker.cpp)
target_link_libraries(spectacles uWS amqpcpp ${ZLIB_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
