
SUBDIRS = include pkgconfig

EXTRA_DIST = \
	autogen.sh \
	debian/changelog \
	debian/compat \
	debian/control \
	debian/copyright \
	debian/icd2-osso-ic-dev.install \
	debian/rules

.PHONY: doxygen-doc

doxygen-doc:
if DOXYGEN_DOCS_ENABLED
	@DOXYGEN@ Doxyfile
endif
