# Install script for directory: /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/xmaster;/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/xmotor;/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/xvision;/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/xpest")
FILE(INSTALL DESTINATION "/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno" TYPE PROGRAM FILES
    "/Network/Servers/duerer/Volumes/duerer/clmc/prog/master/x86_64xeno/xmaster"
    "/Network/Servers/duerer/Volumes/duerer/clmc/prog/master/x86_64xeno/xmotor"
    "/Network/Servers/duerer/Volumes/duerer/clmc/prog/master/x86_64xeno/xvision"
    "/Network/Servers/duerer/Volumes/duerer/clmc/prog/master/x86_64xeno/xpest"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/xrmaster;/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/xrmotor;/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/xrvision")
FILE(INSTALL DESTINATION "/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno" TYPE PROGRAM FILES
    "/Network/Servers/duerer/Volumes/duerer/clmc/prog/master/x86_64xeno/xrmaster"
    "/Network/Servers/duerer/Volumes/duerer/clmc/prog/master/x86_64xeno/xrmotor"
    "/Network/Servers/duerer/Volumes/duerer/clmc/prog/master/x86_64xeno/xrvision"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
