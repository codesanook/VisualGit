AC_INIT([visualgit], [1.0])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([src/config.h])
AM_INIT_AUTOMAKE([-Wall])

AC_PROG_CXX
AC_PROG_CXX_C_O

AM_OPTIONS_WXCONFIG
AM_PATH_WXCONFIG([2.8.12], [wxWin=1])
if test "$wxWin" != 1; then
  AC_MSG_ERROR([
    wxWidgets must be installed on your system.

    Please check that wx-config is in path, the directory
    where wxWidgets libraries are installed (returned by
    'wx-config --libs' or 'wx-config --static --libs' command)
    is in LD_LIBRARY_PATH or equivalent variable and
    wxWidgets version is 2.8.12 or above.
  ])
fi

AC_CONFIG_FILES([Makefile
                 bin/Makefile
                 src/Makefile])
AC_OUTPUT
