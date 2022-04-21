cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(book_store VERSION 1.0)

add_library(mylib STATIC src/book.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/library.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(book_store main.cpp)
target_link_libraries(book_store PUBLIC mylib)