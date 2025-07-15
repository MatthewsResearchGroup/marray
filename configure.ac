AC_INIT(marray,
    m4_normalize(m4_include([VERSION])),
    damatthews@smu.edu,
    marray,
    http://www.github.com/MatthewsResearchGroup/marray
)

test -z $CC || cc_flag="-DCMAKE_C_COMPILER=$CC"
test -z $CXX || cxx_flag="-DCMAKE_CXX_COMPILER=$CXX"

AC_ARG_ENABLE([tests], AS_HELP_STRING([--enable-tests], [Enable unit testing]),
        [test "x$enable_tests" = "xno" && tests_flag="-DENABLE_TESTS=OFF" || tests_flag="-DENABLE_TESTS=ON"])
AC_ARG_ENABLE([coverage], AS_HELP_STRING([--enable-coverage], [Enable code coverage testing with llvm-cov]),
        [test "x$enable_coverage" = "xno" && coverage_flag="-DENABLE_COVERAGE=OFF" || coverage_flag="-DENABLE_COVERAGE=ON"])

cmake \
	-DCMAKE_INSTALL_PREFIX=$prefix \
	-DINSTALL_PREFIX=$prefix \
	-DINSTALL_EXEC_PREFIX=$exec_prefix \
	-DINSTALL_BINDIR=$bindir \
	-DINSTALL_SBINDIR=$sbindir \
	-DINSTALL_LIBEXECDIR=$libexecdir \
	-DINSTALL_SYSCONFDIR=$sysconfdir \
	-DINSTALL_SHAREDSTATEDIR=$sharedstatedir \
	-DINSTALL_LOCALSTATEDIR=$localstatedir \
	-DINSTALL_RUNSTATEDIR=$runstatedir \
	-DINSTALL_LIBDIR=$libdir \
	-DINSTALL_INCLUDEDIR=$includedir \
	-DINSTALL_DATAROOTDIR=$datarootdir \
	-DINSTALL_DATADIR=$datadir \
	-DINSTALL_INFODIR=$infodir \
	-DINSTALL_LOCALEDIR=$localedir \
	-DINSTALL_MANDIR=$mandir \
	-DINSTALL_DOCDIR=$docdir \
	-DINSTALL_HTMLDIR=$htmldir \
	-DINSTALL_DVIDIR=$dvidir \
	-DINSTALL_PDFDIR=$pdfdir \
	-DINSTALL_PSDIR=$psdir \
	\
    $tests_flag \
    $coverage_flag \
    $cc_flag \
    $cxx_flag \
    \
    $srcdir