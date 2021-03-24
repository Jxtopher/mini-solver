## > clang-format ##################################################################
set(CLANG_FORMAT_TO_APPLY "include/*.cpp" 
                          "include/*.h" 
                          "include/*.hpp" 
                          "sources/*.cpp" 
                          "sources/*.h" 
                          "sources/*.hpp" 
                          "tests-unitaires/*.cpp" 
                          "tests-unitaires/*.h" 
                          "tests-unitaires/*.hpp") 

FIND_PROGRAM(CLANGFORMAT_EXECUTABLE clang-format)

file(GLOB_RECURSE ALL_SOURCE_FILES  ${CLANG_FORMAT_TO_APPLY})
foreach (SOURCE_FILE ${ALL_SOURCE_FILES})
    string(FIND ${SOURCE_FILE} ${PROJECT_TRDPARTY_DIR} PROJECT_TRDPARTY_DIR_FOUND)
    if (NOT ${PROJECT_TRDPARTY_DIR_FOUND} EQUAL -1)
        list(REMOVE_ITEM ALL_SOURCE_FILES ${SOURCE_FILE})
    endif ()
endforeach ()

add_custom_target(
        clang-format
        COMMAND ${CLANGFORMAT_EXECUTABLE}
        -style=file
        -i 
        ${ALL_SOURCE_FILES}
)
## < clang-format