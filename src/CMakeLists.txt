add_library(spectacles SHARED brokers/Broker.cpp brokers/AmqpBroker.cpp gateway/Shard.cpp gateway/Manager.cpp)
target_link_libraries(spectacles uWS rabbitmq ${ZLIB_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
