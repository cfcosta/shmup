AC_PREREQ(2.61)

AC_INIT([shmup], [0.1], [cainan.costa@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror])

AC_PROG_CC_C99
AS_IF([test "x$ac_cv_prog_cc_c99" = "xno"], [
  AC_MSG_ERROR([no C99 compiler found.])
])

AM_PROG_CC_C_O

PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([SDL], [sdl])

AC_CONFIG_FILES([Makefile src/Makefile])

AC_OUTPUT
