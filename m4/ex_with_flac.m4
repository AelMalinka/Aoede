dnl Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
dnl Distributed under the terms of the GNU Affero General Public License v3

AC_DEFUN([EX_WITH_FLAC], [
	AC_ARG_WITH([flac],
		[AS_HELP_STRING([--with-flac], [use flac, (required)])],
		[with_flac=$withval],
		[with_flac=check],
	)

	AS_IF([test "x$with_flac" == xno], [AC_MSG_FAILURE([flac is required])],
		[
			test "x$with_flac" != xyes -a "x$with_flac" != xcheck && FLAC_LDFLAGS="-L$with_flac/lib" && FLAC_CPPFLAGS="-L$with_flac/include"
			EX_CHECK_LIBRARY([FLAC], ["FLAC++/stream_decoder.h"], [FLAC++], [], [AC_MSG_FAILURE(["flac: failed to find FLAC"])])
		]
	)

	AC_SUBST([FLAC], [$FLAC_LIBS])
	AM_CONDITIONAL([FLAC], [test "x$FLAC_LIBS" != x])

	AC_DEFINE([HAVE_FLAC], [1], [Define to 1 if FLAC is found])
])
