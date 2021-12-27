file(GLOB SOURCE_FILES *.cpp *.c *.asm)

get_dirname(LIB_NAME)

add_library(${LIB_NAME} ${SOURCE_FILES})
