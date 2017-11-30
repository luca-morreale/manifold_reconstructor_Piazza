cmake_minimum_required(VERSION 2.8.3)

project(manifoldReconstructor)  
   
#----------------------- CMAKE MODULES ------------------------ 

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)  
  
# ----------------------- LIBRARIES ---------------------------
find_package(Boost COMPONENTS filesystem system REQUIRED)
find_package(OpenCV REQUIRED)
find_package(CGAL REQUIRED)
find_package(Eigen3 REQUIRED)

# ----------------------- INCLUDES ----------------------------
include_directories(  ${EIGEN3_INCLUDE_DIR}
                      ${GMPXX_INCLUDE_DIR}
                      ${OpenCV_INCLUDE_DIRS} 
                      ${CGAL_INCLUDE_DIRS}
                      include/
                      include/test/
                      ) 
# ----------------------- GCC FLAGS ----------------------------

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpermissive")

# ------------------------ MESSAGES ----------------------------

# ------------------------ BUILD -------------------------------

file(GLOB_RECURSE meshlib_SOURCE 
                  src/*.cpp
                  src/cam_parsers/*.cpp
                  src/utilities/*.cpp )

file(GLOB_RECURSE meshRec_SOURCE 
                 test/*.cpp
)

add_library(manifoldReconstructor SHARED ${meshlib_SOURCE})

add_executable(meshReconstructor ${meshRec_SOURCE})
target_link_libraries(meshReconstructor manifoldReconstructor
                                            ${OpenCV_LIBS} 
                                            ${GMPXX_LIBRARIES}
                                            ${GMP_LIBRARIES}
                                            ${LAPACK_LIBRARIES}
                                            ${CGAL_LIBRARY}
                                            ${Boost_LIBRARIES}
                                            ${ASSIMP_LIBRARIES}  )


# ------------------------ INSTALLATION ------------------------

install(TARGETS manifoldReconstructor DESTINATION lib)
install(DIRECTORY include/manifoldReconstructor/ DESTINATION include/manifoldReconstructor )

# --------------------------------------------------------------


