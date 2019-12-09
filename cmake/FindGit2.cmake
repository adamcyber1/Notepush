# Find.cmake
#
# Finds the gtest library
#
# This will define the following variables
#
#  Gtest_FOUND             System has gtest libs/headers
#  Gtest_LIBRARIES         The gtest library/libraries
#  GtestMain_LIBRARIES     The gtest_main library/libraries
#  Gtest_INCLUDE_DIR       The location of gtest headers
#
# and the following imported targets
#
#   Gtest::Gtest
#

find_library(Git2_LIBRARIES
        NAMES git2
        )


find_path(Git2_INCLUDE_DIR
        NAMES git2.h
        )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Git2 DEFAULT_MSG
        Git2_LIBRARIES
        Git2_INCLUDE_DIR
        )

mark_as_advanced(
        Git2_LIBRARIES
        Git2_INCLUDE_DIR
)

if(Git2_FOUND AND NOT TARGET Git2::Git2)
    add_library(Git2::Git2 INTERFACE IMPORTED)
    set_target_properties(Git2::Git2 PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${Git2_INCLUDE_DIR}"
            INTERFACE_LINK_LIBRARIES "${Git2_LIBRARIES}"
            )
endif()
