PORTNAME=	rustworkx
DISTVERSION=	0.13.1
PORTREVISION=	2
CATEGORIES=	math python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High performance Python graph library implemented in Rust
WWW=		https://github.com/Qiskit/rustworkx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=5.4:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

CARGO_CRATES=	ahash-0.7.6 \
		ahash-0.8.0 \
		alga-0.9.3 \
		approx-0.3.2 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.11 \
		crossbeam-utils-0.8.12 \
		either-1.8.0 \
		fixedbitset-0.4.2 \
		getrandom-0.2.8 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		indexmap-1.9.3 \
		indoc-1.0.7 \
		itertools-0.10.5 \
		itoa-1.0.4 \
		libc-0.2.137 \
		libm-0.2.6 \
		lock_api-0.4.9 \
		matrixmultiply-0.3.2 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		memoffset-0.9.0 \
		ndarray-0.15.6 \
		ndarray-stats-0.5.1 \
		noisy_float-0.2.0 \
		num-bigint-0.4.3 \
		num-complex-0.2.4 \
		num-complex-0.4.3 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		numpy-0.19.0 \
		once_cell-1.15.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.4 \
		petgraph-0.6.3 \
		ppv-lite86-0.2.16 \
		priority-queue-1.2.2 \
		proc-macro2-1.0.52 \
		pyo3-0.19.1 \
		pyo3-build-config-0.19.1 \
		pyo3-ffi-0.19.1 \
		pyo3-macros-0.19.1 \
		pyo3-macros-backend-0.19.1 \
		quick-xml-0.28.2 \
		quote-1.0.26 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rand_pcg-0.3.1 \
		rawpointer-0.2.1 \
		rayon-1.6.1 \
		rayon-cond-0.2.0 \
		rayon-core-1.10.1 \
		redox_syscall-0.2.16 \
		rustc-hash-1.1.0 \
		ryu-1.0.11 \
		scopeguard-1.1.0 \
		serde-1.0.163 \
		serde_derive-1.0.163 \
		serde_json-1.0.96 \
		smallvec-1.10.0 \
		sprs-0.11.0 \
		syn-1.0.104 \
		syn-2.0.3 \
		target-lexicon-0.12.4 \
		unicode-ident-1.0.5 \
		unindent-0.1.10 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${BUILD_WRKDIR}

PLIST_FILES=	${PYTHON_SITELIBDIR}/rustworkx/rustworkx${PYTHON_EXT_SUFFIX}.so # workaround for https://github.com/Qiskit/rustworkx/issues/654

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rustworkx/rustworkx.cpython-${PYTHON_SUFFIX}.so

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} tox -epy

.include <bsd.port.mk>
