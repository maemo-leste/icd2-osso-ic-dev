AC_INIT([Internet Connectivity daemon 2 OSSO IC OSS compatibility headers], patsubst(esyscmd([dpkg-parsechangelog | sed -n '/^Version: \(.*\)$/ {s//\1/;p}']), [
]),[],[icd2-osso-ic-dev])
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

AC_PREFIX_DEFAULT([/usr])

AC_PROG_MAKE_SET

AC_MSG_CHECKING([wheter to build doxygen documentation])
AC_ARG_ENABLE(doxygen,
	[AS_HELP_STRING([--enable-doxygen],
			[enable doxygen document creation (default=no)]
			)])
if (test x$enable_doxygen = xyes); then
   AC_MSG_RESULT(yes)
   AC_CHECK_PROG(DOXYGEN, doxygen, doxygen, [])
   if (test x$DOXYGEN = x); then
      AC_MSG_WARN([doxygen requested but doxygen not found])
   else
      echo -n
      AC_SUBST(DOXYGEN)
   fi
else
   AC_MSG_RESULT(no)
fi
AM_CONDITIONAL(DOXYGEN_DOCS_ENABLED, [test x$DOXYGEN != x])

AC_OUTPUT([
	Makefile
	include/Makefile
	pkgconfig/Makefile
	pkgconfig/osso-ic.pc
	])
