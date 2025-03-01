# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# compiler must be 11 or 14
SET (CMAKE_CXX_STANDARD 14)

set ( antlr_vscode_generated_files ${CMAKE_CURRENT_SOURCE_DIR}/.antlr )

# set (INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/usr/local)
set (INSTALL_DIR /usr/local)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


list(APPEND ANTLR4CPP_INCLUDE_DIRS ${INSTALL_DIR}/include/antlr4-runtime)
foreach(src_path misc atn dfa tree support)
  list(APPEND ANTLR4CPP_INCLUDE_DIRS ${INSTALL_DIR}/include/antlr4-runtime/${src_path})
endforeach(src_path)

set(ANTLR4CPP_LIBS "${INSTALL_DIR}/lib")

# add antrl4cpp artifacts to project environment
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")


# include generated files in project environment
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
 include_directories(${CMAKE_CURRENT_SOURCE_DIR}/wci)

FILE(GLOB anltr4files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# add generated grammar to binary target
# add_executable(Clouds CloudsMain.cpp ${anltr4files} ${srcfiles})
add_executable(Pcl2 Pcl2.cpp ${anltr4files})

target_link_libraries(Pcl2 antlr4-runtime)
