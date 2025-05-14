include(FetchContent)

FetchContent_Declare(
        entropy-reflection
        GIT_REPOSITORY https://github.com/entropy-software-io/reflection.git
        GIT_TAG        configure-customization
    )

# Enable Runtime Reflection
set (ENTROPY_REFLECTION_ENABLE_RUNTIME ON)

# Don't build the default examples
set (ENTROPY_REFLECTION_BUILD_EXAMPLES OFF)
set (ENTROPY_REFLECTION_BUILD_TESTS OFF)


# These lines below configure the addition of a custom module. They must be set before FetchContent_MakeAvailable

# Include the header file for our custom module. This is added to TypeInfoModuleList.h
set (ENTROPY_REFLECTION_TYPEINFO_EXTRA_MODULE_LIST_INCLUDES "#include \"MyModule.h\"")

# The module we want to add to TypeInfo
set (ENTROPY_REFLECTION_TYPEINFO_EXTRA_MODULE_LIST "MyNamespace::CustomTypeInfo")

# This path is added to the include paths of the reflection library in CMake
set(ENTROPY_REFLECTION_EXTRA_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/../Include")


# Tell CMake to step into the dowloaded entropy-reflection repo as if we did add_subdirectory()
FetchContent_MakeAvailable(entropy-reflection)
