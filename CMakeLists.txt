cmake_minimum_required(VERSION 3.6)
project("cpp-odb-sqlite-http-json-rest-service")

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES src/*.cpp)
file(GLOB_RECURSE ${PROJEC_NAME}_ODB_HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/odb/*.hxx)
list(APPEND ${PROJEC_NAME}_HEADERS ${CMAKE_CURRENT_LIST_DIR}/include)
list(APPEND ${PROJEC_NAME}_HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/odb)

message(STATUS "${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES}")

# find_package(PkgConfig)
# pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

find_package(Threads REQUIRED)

find_package(ODB REQUIRED
    COMPONENTS boost sqlite
    OPTIONAL_COMPONENTS mysql)

include(${ODB_USE_FILE})

find_package(Boost 1.56 REQUIRED COMPONENTS system date_time filesystem iostreams thread)

odb_compile(
    HEADERS ${${PROJEC_NAME}_ODB_HEADERS}
    INCLUDES ${${PROJEC_NAME}_HEADERS}
    DB sqlite
    STANDARD c++14
    GENERATE_QUERY GENERATE_SESSION GENERATE_SCHEMA
	HEADER_SUFFIX ".hpp"
	INLINE_SUFFIX ".ipp"
	SOURCE_SUFFIX ".cpp"
	FILE_SUFFIX ".hxx"
    DEFAULT_POINTER "std::shared_ptr"
)

message(STATUS "ODB_GENERATED_SOURCES: ${ODB_GENERATED_SOURCES}")

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES} ${ODB_GENERATED_SOURCES})

# target_link_libraries(${PROJECT_NAME} PkgConfig::Pistache)
target_link_libraries(${PROJECT_NAME} ${ODB_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Threads::Threads)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

message(STATUS "ODB_INCLUDE_DIRS: ${ODB_INCLUDE_DIRS}")
message(STATUS "${PROJEC_NAME}_HEADERS: ${${PROJEC_NAME}_HEADERS}")

target_include_directories(${PROJECT_NAME} PRIVATE ${ODB_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${${PROJEC_NAME}_HEADERS})

target_compile_definitions(${PROJECT_NAME} PRIVATE DATABASE_SQLITE)