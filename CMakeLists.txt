# CMakeList.txt : CMake project for miniroot, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("miniroot")


# Exception (MSVC C4530)
#IF(MSVC)
#    SET(CMAKE_CXX_FLAGS "/EHsc")
#ENDIF(MSVC)

# Chek root presence.
#find_package(ROOT REQUIRED)
find_package(ROOT REQUIRED COMPONENTS RIO Net)

# Add main target executable.
add_executable (miniroot)

# Set language version. 
set_property(TARGET miniroot PROPERTY CXX_STANDARD 17)
set_property(TARGET miniroot PROPERTY CXX_STANDARD_REQUIRED YES)
#set_property(TARGET miniroot PROPERTY COMPILE_FLAGS -Zc:__cplusplus) # This is required to full root compatibility.
set_property(TARGET miniroot PROPERTY COMPILE_FLAGS ${ROOT_CXX_FLAGS}) # Ensures full root libraries compatibility.

# Add ROOT includes.
target_include_directories(miniroot PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/include	
	${ROOT_INCLUDE_DIRS}
)

# Add ROOT libraries.
target_link_libraries (miniroot PRIVATE 
    ${ROOT_LIBRARIES}
)


# Add target own code.
target_sources(miniroot PRIVATE 
	 "miniroot.cpp"
)

# Set build mode
set_property(TARGET miniroot PROPERTY DCMAKE_BUILD_TYPE Release)



# TODO: Add tests and install targets if needed.
