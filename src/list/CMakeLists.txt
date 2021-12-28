file(GLOB SOURCE_FILES *.cpp *.c *.asm)

get_dirname(LIB_NAME)

add_library(${LIB_NAME} ${SOURCE_FILES})

add_executable(list_test list_test.cpp)
target_link_libraries(list_test ${LIB_NAME} Catch2::Catch2WithMain)
add_test(NAME list_test COMMAND list_test)