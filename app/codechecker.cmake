# CodeChecker setup, see codechecker.yaml

set(
    CODECHECKER_CONFIG_FILE
    "${CMAKE_CURRENT_LIST_DIR}/codechecker.yaml;"
    CACHE STRING
    "CodeChecker configuration file"
)

set(
    CODECHECKER_ANALYZE_OPTS
    "--analyzer-config;cppcheck:cc-verbatim-args-file=${CMAKE_BINARY_DIR}/sca/cppcheck/cc-verbatim-args.txt;"
    "--skip;${CMAKE_CURRENT_LIST_DIR}/codechecker.skip"
    CACHE STRING
    "CodeChecker analyzer options"
)

set(
    CODECHECKER_EXPORT
    "html"
    CACHE STRING
    "HTML report"
)
