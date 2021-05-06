cmake_minimum_required(VERSION 3.14)
project(nitron)

set (CXX11_FOUND "1")

set(CMAKE_CXX_STANDARD 11)

include(ExternalProject)

# HTSLIB
include_directories("${CMAKE_SOURCE_DIR}/include/")
link_directories("${CMAKE_SOURCE_DIR}/include/htslib")
ExternalProject_Add(htslib
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/include/htslib/
        BUILD_IN_SOURCE 1
        CONFIGURE_COMMAND autoheader COMMAND autoconf COMMAND ./configure --without-libdeflate --disable-libcurl
        BUILD_COMMAND ${MAKE}
        INSTALL_COMMAND ""
        )

link_directories("${CMAKE_SOURCE_DIR}/include/LightGBM")
ExternalProject_Add(lightgbm
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/include/LightGBM/
        BUILD_ALWAYS OFF
        BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config Release
)


add_executable(nitron
               src/nitron.cpp
               src/arg_parse.hpp
               src/arg_parse.cpp)

add_dependencies(nitron htslib)
target_link_libraries (nitron pthread -lhts -lz -llzma -lbz2)
