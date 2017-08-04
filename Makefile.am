# Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
# Distributed under the terms of the GNU Affero General Public License v3

ACLOCAL_AMFLAGS = -Im4
AM_CPPFLAGS = -I$(srcdir)/src

mainheadersdir = $(includedir)/Entropy/Aoede
mainheaders_HEADERS = \
	src/Application.hh \
	src/Exception.hh \
	src/Flac.hh \
	src/Types.hh

alheadersdir = $(includedir)/Entropy/Aoede/AL
alheaders_HEADERS = \
	src/AL/Buffer.hh \
	src/AL/Context.hh \
	src/AL/Device.hh \
	src/AL/Listener.hh \
	src/AL/Source.hh

lib_LTLIBRARIES = libaoede.la

libaoede_la_SOURCES = \
	src/AL/Buffer.cc \
	src/AL/Context.cc \
	src/AL/Device.cc \
	src/AL/Listener.cc \
	src/AL/Source.cc \
	src/Application.cc \
	src/Flac.cc
libaoede_la_LDFLAGS = -version-info 0

check_PROGRAMS =

if GTEST
check_PROGRAMS += \
	al-buffer \
	al-context \
	al-device \
	al-listener \
	al-source \
	basic-application

gtestLDADD = $(GTEST_LIBS) -lgtest_main libaoede.la

al_buffer_SOURCES = test/AL/buffer.cc
al_buffer_LDADD = $(gtestLDADD)

al_context_SOURCES = test/AL/context.cc
al_context_LDADD = $(gtestLDADD)

al_device_SOURCES = test/AL/device.cc
al_device_LDADD = $(gtestLDADD)

al_source_SOURCES = test/AL/source.cc
al_source_LDADD = $(gtestLDADD)

al_listener_SOURCES = test/AL/listener.cc
al_listener_LDADD = $(gtestLDADD)

basic_application_SOURCES = test/basic/application.cc
basic_application_LDADD = $(gtestLDADD)
endif

TESTSUITE = $(srcdir)/test/testsuite

TESTSUITE_FILES = \
	$(srcdir)/test/al.at

EXTRA_DIST = $(TESTSUITE_FILES) \
	$(srcdir)/test/testsuite.at \
	$(srcdir)/package.m4 \
	$(TESTSUITE) \
	$(srcdir)/test/atlocal.in

$(srcdir)/package.m4: $(top_srcdir)/configure.ac
	:; {\
		echo '# Signature of the current package. (auto-generated)' && \
		echo 'm4_define([AT_PACKAGE_NAME],' && \
		echo '  [$(PACKAGE_NAME)])' && \
		echo 'm4_define([AT_PACKAGE_TARNAME],' && \
		echo '  [$(PACKAGE_TARNAME)])' && \
		echo 'm4_define([AT_PACKAGE_VERSION],' && \
		echo '  [$(PACKAGE_VERSION)])' && \
		echo 'm4_define([AT_PACKAGE_STRING],' && \
		echo '  [$(PACKAGE_STRING)])' && \
		echo 'm4_define([AT_PACKAGE_BUGREPORT],' && \
		echo '  [$(PACKAGE_BUGREPORT)])'; \
		echo 'm4_define([AT_PACKAGE_URL],' && \
		echo '  [$(PACKAGE_URL)])'; \
	} >'$(srcdir)/package.m4'

check-local: test/atconfig atlocal $(TESTSUITE) $(check_PROGRAMS)
	$(SHELL) '$(TESTSUITE)' AUTOTEST_PATH='$(shell pwd)' $(TESTSUITEFLAGS)

clean-local:
	test ! -f '$(TESTSUITE)' || \
		$(SHELL) '$(TESTSUITE)' --clean

AUTOM4TE = $(SHELL) $(srcdir)/build-aux/missing --run autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest
$(TESTSUITE): $(srcdir)/test/testsuite.at $(TESTSUITE_FILES) $(srcdir)/package.m4
	$(AUTOTEST) -I '$(srcdir)/test' -I $(srcdir) -o $@.tmp $@.at
	mv $@.tmp $@
