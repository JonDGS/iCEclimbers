# Install script for directory: D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/libraries/cJSON

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/UI")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/UI/include/cjson/cJSON.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/UI/include/cjson" TYPE FILE FILES "D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/libraries/cJSON/cJSON.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/UI/lib/pkgconfig/libcjson.pc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/UI/lib/pkgconfig" TYPE FILE FILES "D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/libcjson.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/UI/lib/libcjson.dll.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/UI/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/libcjson.dll.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/UI/bin/libcjson.dll")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/UI/bin" TYPE SHARED_LIBRARY FILES "D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/libcjson.dll")
  if(EXISTS "$ENV{DESTDIR}/C:/Program Files (x86)/UI/bin/libcjson.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/C:/Program Files (x86)/UI/bin/libcjson.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/strip.exe" "$ENV{DESTDIR}/C:/Program Files (x86)/UI/bin/libcjson.dll")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}C:/Program Files (x86)/UI/lib/cmake/cJSON/cjson.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}C:/Program Files (x86)/UI/lib/cmake/cJSON/cjson.cmake"
         "D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/CMakeFiles/Export/C_/Program_Files_(x86)/UI/lib/cmake/cJSON/cjson.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}C:/Program Files (x86)/UI/lib/cmake/cJSON/cjson-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}C:/Program Files (x86)/UI/lib/cmake/cJSON/cjson.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/UI/lib/cmake/cJSON/cjson.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/UI/lib/cmake/cJSON" TYPE FILE FILES "D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/CMakeFiles/Export/C_/Program_Files_(x86)/UI/lib/cmake/cJSON/cjson.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "C:/Program Files (x86)/UI/lib/cmake/cJSON/cjson-debug.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/UI/lib/cmake/cJSON" TYPE FILE FILES "D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/CMakeFiles/Export/C_/Program_Files_(x86)/UI/lib/cmake/cJSON/cjson-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/UI/lib/cmake/cJSON/cJSONConfig.cmake;C:/Program Files (x86)/UI/lib/cmake/cJSON/cJSONConfigVersion.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/UI/lib/cmake/cJSON" TYPE FILE FILES
    "D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/cJSONConfig.cmake"
    "D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/cJSONConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/tests/cmake_install.cmake")
  include("D:/OneDrive TEC/OneDrive - Estudiantes ITCR/GITHUB/iCEclimbers/iCEclimbers/scr/UI/cmake-build-debug/libraries/cJSON/fuzzing/cmake_install.cmake")

endif()

