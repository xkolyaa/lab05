add_library(solver_lib STATIC
    sources/solver.cpp
)

target_include_directories(solver_lib PUBLIC include)
