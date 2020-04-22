cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(test)

# Sources
file(GLOB_RECURSE sources src/*.[hc]pp)

# Executable
add_executable(testApp ${sources} src/main.manifest)

set_target_properties(testApp PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)

if(WIN32)
  target_compile_definitions(testApp PRIVATE WIN32_LEAN_AND_MEAN _SCL_SECURE_NO_WARNINGS _USE_MATH_DEFINES)
endif()

if(MSVC)
  target_compile_options(testApp PRIVATE
    $<$<CONFIG:Release>:/openmp>
    $<$<CONFIG:Debug>:/bigobj>)
endif()

# Dependencies
find_package(OpenCV REQUIRED)
target_include_directories(testApp PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(testApp PRIVATE ${OpenCV_LIBS})

# Install
install(TARGETS testApp RUNTIME DESTINATION bin)

if(WIN32)
  install(CODE [[
    file(GLOB libraries $<TARGET_FILE_DIR:testApp>/*.dll)
    file(INSTALL ${libraries} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
  ]])
endif()
