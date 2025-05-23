include(FetchContent)

FetchContent_Declare(
        entropy-reflection
        GIT_REPOSITORY https://github.com/entropy-software-io/reflection.git
        GIT_TAG        9ecc4d5413468f0092a1cd866cfdb49ed9fae32f
    )

# Enable Runtime Reflection (On by default)
set (ENTROPY_REFLECTION_ENABLE_RUNTIME ON)

# Build examples and tests. Normally, this wouldn't be done.
set (ENTROPY_REFLECTION_BUILD_EXAMPLES ON)
set (ENTROPY_REFLECTION_BUILD_TESTS ON)


# These lines below configure the addition of a custom module. They must be set before FetchContent_MakeAvailable

# Include the header file for our custom module. This is added to TypeInfoModuleList.h
set (ENTROPY_REFLECTION_TYPEINFO_EXTRA_MODULE_LIST_INCLUDES "#include \"MyModule.h\"")

# The module we want to add to TypeInfo
set (ENTROPY_REFLECTION_TYPEINFO_EXTRA_MODULE_LIST "MyNamespace::CustomTypeInfo")

# This path is added to the include paths of the reflection library in CMake
set(ENTROPY_REFLECTION_EXTRA_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/../Include")



# Set custom containers

set (ENTROPY_CORE_CUSTOM_VECTOR_INCLUDES "#include \"MyCustomVector.h\"")
set (ENTROPY_CORE_CUSTOM_MAP_INCLUDES "#include \"MyCustomMap.h\"")

# This path is added to the include paths of the core libraries in CMake
set(ENTROPY_CORE_EXTRA_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/../Include")


# Tell CMake to step into the dowloaded entropy-reflection repo as if we did add_subdirectory()
FetchContent_MakeAvailable(entropy-reflection)
