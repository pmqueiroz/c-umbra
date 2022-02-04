#!/bin/bash

VCPKG__DIR="./vcpkg"
VCPKG__EXEC="$VCPKG__DIR/vcpkg"
DEPENDENCIES=("greatest")

if [ -d "$VCPKG__DIR" ]; then
   if [ -f "$VCPKG__EXEC" ]; then
      echo "vcpkg build found"
   else
      echo "Installing vcpkg"
      $VCPKG__DIR/bootstrap-vcpkg.
   fi

   for DEPENDENCY in "${DEPENDENCIES[@]}"
   do
      echo "Installing $DEPENDENCY"
      $VCPKG__EXEC install $DEPENDENCY
   done

else
   echo "vcpkg not found please run \"git submodule update --init\""
   exit 1
fi
