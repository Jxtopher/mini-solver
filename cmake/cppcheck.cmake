## > cppcheck ##################################################################
set(CPPCHECK_TO_APPLY "sources/*.cpp" 
                          "sources/*.h" 
                          "sources/*.hpp" 
                          "tests/*.cpp" 
                          "tests/*.h" 
                          "tests/*.hpp") 

## Detection du programme cppcheck
FIND_PROGRAM(CPPCHECK_EXECUTABLE cppcheck)

## 
SET(PROJECT_TRDPARTY_DIR third-party)

file(GLOB_RECURSE ALL_SOURCE_FILES ${CPPCHECK_TO_APPLY})
foreach (SOURCE_FILE ${ALL_SOURCE_FILES})
    string(FIND ${SOURCE_FILE} ${PROJECT_TRDPARTY_DIR} PROJECT_TRDPARTY_DIR_FOUND)
    if (NOT ${PROJECT_TRDPARTY_DIR_FOUND} EQUAL -1)
        list(REMOVE_ITEM ALL_SOURCE_FILES ${SOURCE_FILE})
    endif ()
endforeach ()

add_custom_target(
        cppcheck
        COMMAND ${CPPCHECK_EXECUTABLE}
        --enable=warning,performance,portability,information,missingInclude
        --std=c++11
        --library=qt.cfg
        --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
        --verbose
        --quiet
        ${ALL_SOURCE_FILES}
)
## < cppcheck
