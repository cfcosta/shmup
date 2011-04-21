AC_PREREQ(2.61)

AC_INIT([shmup], [0.1], [cainan.costa@gmail.com])

AC_PROG_CC_C99
AS_IF([test "x$ac_cv_prog_cc_c99" = "xno"], [
  AC_MSG_ERROR([no C99 compiler found.])
])

PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([SDL], [sdl])
