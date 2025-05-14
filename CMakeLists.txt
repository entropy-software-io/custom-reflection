add_subdirectory(Dependencies)

set (SRC_FILES "Src/Main.cpp")
add_executable(entropy-custom-reflection ${SRC_FILES})

target_link_libraries(entropy-custom-reflection PRIVATE entropy::reflection)
