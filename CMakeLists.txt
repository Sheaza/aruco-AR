
cmake_minimum_required(VERSION 3.2.0 )
project( DisplayImage )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_PARALLEL_LEVEL 4)

set(OpenCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin/opencv")
set(OpenCV_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/bin/opencv/x64/vc17/bin")
set(OpenCV_LIBS "opencv_highgui")
set(PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin/opencv/x64/vc17/lib;
	${CMAKE_CURRENT_SOURCE_DIR}/bin/opencv/x64/vc17/bin;
	$ENV{PATH}")

message(" ")
message("_____")
message( "CURRENT_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message( "OpenCV_DIR = ${OpenCV_DIR}")
message( "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message( "OpenCV_LIBS = ${OpenCV_LIBS}")
message("_____")

find_package(OpenCV REQUIRED PATHS "${CMAKE_CURRENT_SOURCE_DIR}/bin/opencv")
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( DisplayImage src/main.cpp )

target_link_libraries( DisplayImage ${OpenCV_LIBS} )


