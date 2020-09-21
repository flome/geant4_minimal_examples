
# which cmake to use at least, otherwise fail
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# set up cmake project
project(SimulationAppProject)

# tell the compiler where to find the actual files
include_directories(${PROJECT_SOURCE_DIR}/include)

# collect names of the user code source files
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)

# tell the compiler which source files need to be compiled
add_executable(G4SimApp main.cc ${sources})

# locate Geant4 installation
find_package(Geant4 REQUIRED)

# include compilation definitions for Geant4
include(${Geant4_USE_FILE})

# link against Geant4 libraries
target_link_libraries(G4SimApp ${Geant4_LIBRARIES})
