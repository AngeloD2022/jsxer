cmake_minimum_required(VERSION 3.26)

project(Jsxer)

# using c++17 to use some modern features of c++
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# Needed to print downloading progress
Set(FETCHCONTENT_QUIET FALSE)

# string formatting
FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 9.1.0
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(fmt)

# logger
FetchContent_Declare(plog
    GIT_REPOSITORY https://github.com/SergiusTheBest/plog.git
    GIT_TAG 1.1.9
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(plog)

# cli parser
FetchContent_Declare(cli11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(cli11)

# utils

file(STRINGS "VERSION" JSXER_VERSION)

message("${PROJECT_NAME} v${JSXER_VERSION}")

set(JSXER_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(JSXER_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE)

message("Build: " "${CMAKE_BUILD_TYPE}")

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(BUILD_ARCH "64-bit")
else()
    set(BUILD_ARCH "32-bit")
endif()

message("System Architecture: " "${CMAKE_SYSTEM_PROCESSOR}")
message("System Bitness: " "${BUILD_ARCH}")

if(MSVC OR MSYS OR MINGW)
    # for detecting Windows compilers
    set(BUILD_PLATFORM "Windows")

    set(BIN_CLI_EXT ".exe")
    set(BIN_DLL_EXT ".dll")
    set(BIN_LIB_EXT ".lib")
elseif(UNIX AND NOT APPLE)
    # for Linux, BSD, Solaris, Minix
    set(BUILD_PLATFORM "Linux")

    set(BIN_CLI_EXT "")
    set(BIN_DLL_EXT ".so")
    set(BIN_LIB_EXT ".a")
elseif(APPLE)
    # for MacOS X or iOS, watchOS, tvOS (since 3.10.3)
    set(BUILD_PLATFORM "Darwin")

    set(BIN_CLI_EXT "")
    set(BIN_DLL_EXT ".dylib")
    set(BIN_LIB_EXT ".a")
else()
    message(FATAL_ERROR "Unknown platform!, CMake will exit.")
endif()

message("Platform: " "${BUILD_PLATFORM}")

if(BUILD_TYPE STREQUAL "debug")
    set(BIN_OUT_DIR ${PROJECT_SOURCE_DIR}/bin/debug)
else()
    set(BIN_OUT_DIR ${PROJECT_SOURCE_DIR}/bin/release)
endif()

set(LIB_OUT_DIR ${BIN_OUT_DIR}/static)
set(DLL_OUT_DIR ${BIN_OUT_DIR}/dll)

message("Bin directory: " "${BIN_OUT_DIR}")
message("Lib directory: " "${LIB_OUT_DIR}")
message("Dll directory: " "${DLL_OUT_DIR}")

set(BIN_CLI_NAME "jsxer")
set(BIN_DLL_NAME "lib-jsxer")
set(BIN_LIB_NAME "libjsxer")

# Static lib
set(JSXER_CORE_TARGET jsxer-core)

file(GLOB_RECURSE JSXER_CORE_HEADERS
    ${JSXER_SOURCE_DIR}/jsxer/*.h
    ${JSXER_SOURCE_DIR}/jsxer/*.hpp
)

file(GLOB_RECURSE JSXER_CORE_SOURCES
    ${JSXER_SOURCE_DIR}/jsxer/*.c
    ${JSXER_SOURCE_DIR}/jsxer/*.cpp
)

add_library(${JSXER_CORE_TARGET} STATIC ${JSXER_CORE_HEADERS} ${JSXER_CORE_SOURCES})

target_include_directories(${JSXER_CORE_TARGET} PUBLIC ${JSXER_INCLUDE_DIR})

target_link_libraries(${JSXER_CORE_TARGET} PRIVATE
        fmt::fmt
        plog::plog
        )

target_compile_definitions(${JSXER_CORE_TARGET} PUBLIC
    CONFIG_VERSION="${JSXER_VERSION}"
)

set_target_properties(${JSXER_CORE_TARGET} PROPERTIES
    PREFIX ""
    SUFFIX "${BIN_LIB_EXT}"
    OUTPUT_NAME "${BIN_LIB_NAME}"
    LIBRARY_OUTPUT_DIRECTORY ${LIB_OUT_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${LIB_OUT_DIR}
)

# Dynamic link library
set(JSXER_DLL_TARGET jsxer-dll)

file(GLOB_RECURSE JSXER_DLL_HEADERS
    ${JSXER_SOURCE_DIR}/dll/*.h
    ${JSXER_SOURCE_DIR}/dll/*.hpp
)

file(GLOB_RECURSE JSXER_DLL_SOURCES
    ${JSXER_SOURCE_DIR}/dll/*.c
    ${JSXER_SOURCE_DIR}/dll/*.cpp
)

add_library(${JSXER_DLL_TARGET} SHARED ${JSXER_DLL_HEADERS} ${JSXER_DLL_SOURCES})

target_link_libraries(${JSXER_DLL_TARGET} PRIVATE ${JSXER_CORE_TARGET}
        fmt::fmt
        plog::plog)

target_compile_definitions(${JSXER_DLL_TARGET} PUBLIC
    CONFIG_VERSION="${JSXER_VERSION}"
)

set_target_properties(${JSXER_DLL_TARGET} PROPERTIES
    PREFIX ""
    SUFFIX "${BIN_DLL_EXT}"
    OUTPUT_NAME "${BIN_DLL_NAME}"
    RUNTIME_OUTPUT_DIRECTORY ${DLL_OUT_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${DLL_OUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${DLL_OUT_DIR}
)

# CLI
set(JSXER_CLI_TARGET jsxer-cli)

file(GLOB_RECURSE JSXER_CLI_HEADERS
    ${JSXER_SOURCE_DIR}/cli/*.h
    ${JSXER_SOURCE_DIR}/cli/*.hpp
)

file(GLOB_RECURSE JSXER_CLI_SOURCES
    ${JSXER_SOURCE_DIR}/cli/*.c
    ${JSXER_SOURCE_DIR}/cli/*.cpp
)

add_executable(${JSXER_CLI_TARGET} ${JSXER_CLI_HEADERS} ${JSXER_CLI_SOURCES})

target_link_libraries(${JSXER_CLI_TARGET} PRIVATE ${JSXER_CORE_TARGET}
        fmt::fmt
        plog::plog
        CLI11::CLI11
        )

target_compile_definitions(${JSXER_CLI_TARGET} PUBLIC
    CONFIG_VERSION="${JSXER_VERSION}"
)

set_target_properties(${JSXER_CLI_TARGET} PROPERTIES
    PREFIX ""
    SUFFIX "${BIN_CLI_EXT}"
    OUTPUT_NAME "${BIN_CLI_NAME}"
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUT_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${BIN_OUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${BIN_OUT_DIR}
)

enable_testing()

set(JSXER_TESTS_DIR ${CMAKE_CURRENT_LIST_DIR}/tests)

set(JSXER_TESTS_SRC_DIR ${JSXER_TESTS_DIR}/src)
set(JSXER_TESTS_DATA_DIR ${JSXER_TESTS_DIR}/data)

add_executable(jsxer-test-array-expr ${JSXER_TESTS_SRC_DIR}/array-expr.cpp)
target_link_libraries(jsxer-test-array-expr PRIVATE ${JSXER_CORE_TARGET})

add_test("ArrayExpression" jsxer-test-array-expr)

add_executable(jsxer-test-obj-expr ${JSXER_TESTS_SRC_DIR}/obj-expr.cpp)
target_link_libraries(jsxer-test-obj-expr PRIVATE ${JSXER_CORE_TARGET})

add_test("ObjectExpression" jsxer-test-obj-expr)

add_executable(jsxer-test-member-expr ${JSXER_TESTS_SRC_DIR}/member-expr.cpp)
target_link_libraries(jsxer-test-member-expr PRIVATE ${JSXER_CORE_TARGET})

add_test("MemberExpression" jsxer-test-member-expr)

add_executable(jsxer-test-for-stmt ${JSXER_TESTS_SRC_DIR}/for-stmt.cpp)
target_link_libraries(jsxer-test-for-stmt PRIVATE ${JSXER_CORE_TARGET})

add_test("ForStatement" jsxer-test-for-stmt)
