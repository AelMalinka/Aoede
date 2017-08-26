dnl Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
dnl Distributed under the terms of the GNU Affero General Public License v3

AC_DEFUN([EX_WITH_OPENAL], [
	AC_ARG_WITH([openal],
		[AS_HELP_STRING([--with-openal], [use openal, (required)])],
		[with_openal=$withval],
		[with_openal=check]
	)

	AS_IF([test "x$with_openal" = xno], [AC_MSG_FAILURE([openal is required])],
		[
			test "x$with_openal" != xyes -a "x$with_openal" != xcheck && OPENAL_LDFLAGS="-L$with_openal/lib" && OPENAL_CPPFLAGS="-L$with_openal/include"
			EX_CHECK_LIBRARY([OPENAL], ["AL/al.h"], [openal], [], [AC_MSG_FAILURE(["openal: failed to find al"])])
			AC_CHECK_HEADER([AL/alc.h], [], [AC_MSG_FAILURE(["openal: failed to find AL/alc.h"])])
		]
	)

	AC_SUBST([OPENAL], [$OPENAL_LIBS])
	AM_CONDITIONAL([OPENAL], [test "x$OPENAL_LIBS" != x])

	AC_DEFINE([HAVE_OPENAL], [1], [Define to 1 if OpenAL is found])
])
