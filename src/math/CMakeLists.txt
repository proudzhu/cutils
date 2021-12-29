file(GLOB SOURCE_FILES *.cpp *.c *.asm)

get_dirname(LIB_NAME)

add_library(${LIB_NAME} ${SOURCE_FILES})

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test ${LIB_NAME} Catch2::Catch2WithMain)
add_test(NAME rational_test COMMAND rational_test)
