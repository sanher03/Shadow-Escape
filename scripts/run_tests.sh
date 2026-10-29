#!/usr/bin/env bash

set -u

project_root=$(cd -- "$(dirname -- "$0")/.." && pwd)
cd "$project_root"

usage() {
  echo "Uso: $0 <0|1> [test]" >&2
  echo "  0: ejecutar sin Valgrind; 1: ejecutar con Valgrind" >&2
  echo "  test: test individual (por ejemplo, command_test)" >&2
}

if [[ $# -lt 1 || $# -gt 2 || ( $1 != 0 && $1 != 1 ) ]]; then
  usage
  exit 2
fi

mode=$1
tests=(
  command_test
  enemy_test
  game_management_test
  game_test
  inventory_test
  link_test
  object_test
  player_test
  set_test
  space_test
)

if [[ $# -eq 1 ]]; then
  make test || exit $?
else
  selected_test=$2
  valid_test=0
  for test in "${tests[@]}"; do
    if [[ $test == "$selected_test" ]]; then
      valid_test=1
      break
    fi
  done
  if [[ $valid_test -ne 1 ]]; then
    echo "Prueba no reconocida: $selected_test" >&2
    usage
    exit 2
  fi
  make "$selected_test" || exit $?
  tests=("$selected_test")
fi

if [[ $mode -eq 1 ]] && ! command -v valgrind >/dev/null 2>&1; then
  echo "Error: Valgrind no está instalado." >&2
  exit 1
fi

status=0
for test in "${tests[@]}"; do
  echo "==> $test"
  if [[ $mode -eq 1 ]]; then
    valgrind --leak-check=full "./bin/$test" || status=1
  else
    "./bin/$test" || status=1
  fi
done

exit "$status"
