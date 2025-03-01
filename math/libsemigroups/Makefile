PORTNAME=	libsemigroups
PORTVERSION=	1.3.7
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library for semigroups and monoids
WWW=		https://libsemigroups.readthedocs.io/en/latest/

LICENSE=	GPLv3

BUILD_DEPENDS=	HPCombi>0:math/hpcombi
LIB_DEPENDS=	libfmt.so:devel/libfmt

USE_GITHUB=	yes

USES=		autoreconf compiler:c++11-lang eigen:3,build \
		libtool pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fmt --with-external-fmt=yes	\
		--with-external-eigen
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64
CONFIGURE_ARGS+=	--disable-hpcombi
.endif

pre-configure:
.if ${ARCH} == amd64
	${REINPLACE_CMD} -e 's|$$srcdir/extern/HPCombi|${LOCALBASE}/share/HPCombi|'	\
		${WRKSRC}/m4/ax_check_hpcombi.m4
	${REINPLACE_CMD} -e 's|extern/HPCombi/include|${LOCALBASE}/include/HPCombi|'	\
		${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -e 's|HPCombi/include|HPCombi|'	\
		${WRKSRC}/include/libsemigroups/hpcombi.hpp
.endif
	${REINPLACE_CMD} -e 's|fmtinclude_HEADERS|#fmtinclude_HEADERS|'	\
		-e 's|-O3 ||' ${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
