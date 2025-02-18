#!/bin/bash

set -eo pipefail

cd "$(dirname "$0")"

usage() {
    echo "Usage: build.sh <task> <mode>?"
    exit 1
}

OUT=out

CXX=$(which clang++)
CXXFLAGS="-std=c++20 -Wall -Wextra -Wpedantic -Werror -g"
CXXFLAGS_RELEASE="$CXXFLAGS -O3 -DNDEBUG"
CXXFLAGS_ASAN="$CXXFLAGS -fsanitize=address,undefined,leak"

if [[ $# -eq 1 ]]; then
  MODE=$1
elif [[ $# -eq 2 ]]; then
  TASK=$1
  MODE=$2

  if [ -z "$TASK" ]; then
      echo "Invalid argument: TASK must be set."
      usage
  fi

  echo "Got TASK: $TASK"
fi

if [ "$MODE" = "Release" ]; then
    CXXFLAGS_TOTAL="$CXXFLAGS_RELEASE"
elif [ "$MODE" = "Asan" ]; then
    CXXFLAGS_TOTAL="$CXXFLAGS_ASAN"
else
    echo "Invalid argument: MODE must be either 'Release' or 'Asan'."
    usage
fi

echo "Got MODE: $MODE"

TASKS=()

if [[ -n "$TASK" ]]; then
  TASKS+="$TASK"
else
  for tt in $(ls ../contest); do
    TASKS+=("contest/$tt")
  done
fi

for T in "${TASKS[@]}"; do
  echo "Building $T"
  mkdir -p ../$OUT/$T
  "$CXX" $CXXFLAGS_TOTAL "../$T/Main.cpp" -o "../$OUT/$T/App$MODE"
done
