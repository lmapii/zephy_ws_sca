# this prepares the cppcheck integration for CodeChecker and Zephyr
# it creates a `cppcheck_cc.h` file with options implicitly passed by the selected toolchain
# and creates a `cc-verbatim-args.txt` file for the required includes with Zephyr projects.
# the `cc-verbatim-args.txt` can be used with CodeChecker's
# `--analyzer-config cppcheck:cc-verbatim-args-file=<filepath>`

set(output_dir ${CMAKE_BINARY_DIR}/sca/cppcheck)
file(MAKE_DIRECTORY ${output_dir})

if(NOT EXISTS ${output_dir}/empty.c)
  file(WRITE ${output_dir}/empty.c "")
endif()

if(DEFINED CMAKE_C_COMPILER_TARGET)
  set(cc_target "--target=${CMAKE_C_COMPILER_TARGET}")
endif()

add_custom_target(cppcheck_generate_compiler_header ALL
  COMMAND ${CMAKE_C_COMPILER}
    ${TOOLCHAIN_C_FLAGS}
    ${cc_target}
    -E -dM
    ${output_dir}/empty.c > ${output_dir}/cppcheck_cc.h
  DEPENDS ${output_dir}/empty.c
  COMMENT "Generating cppcheck_cc.h"
  BYPRODUCTS ${output_dir}/cppcheck_cc.h
  VERBATIM
)

set(CPPCHECK_VERBATIM_ARGS
  "--include=${output_dir}/cppcheck_cc.h"
  "--include=${PROJECT_BINARY_DIR}/include/generated/zephyr/autoconf.h"
  ${CPPCHECK_VERBATIM_EXTRA_ARGS}
)

# if(NOT EXISTS ${output_dir}/cc-verbatim-args.txt)
list(JOIN CPPCHECK_VERBATIM_ARGS " " CPPCHECK_VERBATIM_ARGS_STR)
file(WRITE ${output_dir}/cc-verbatim-args.txt "${CPPCHECK_VERBATIM_ARGS_STR}")
# endif()
