include(FetchContent)

FetchContent_Declare(
        entropy-reflection
        GIT_REPOSITORY https://github.com/entropy-software-io/reflection.git
        GIT_TAG        working
    )

# Enable Runtime Reflection
set (ENTROPY_REFLECTION_ENABLE_RUNTIME ON)

set (ENTROPY_BUILD_EXAMPLES OFF)
set (ENTROPY_BUILD_TESTS OFF)

FetchContent_MakeAvailable(entropy-reflection)
