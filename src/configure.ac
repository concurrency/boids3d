AC_INIT([occam-mar2016], [0.1], [frmb@kent.ac.uk])
AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE

dnl Checks for programs.
OCCAM_OCCBUILD

have_cuda=yes
build_cuda=yes

OCCAM_HAVE_CUDA(4.2, sm_20, , [have_cuda=no])
build_cuda=$have_cuda

OCCAM_INCLUDE([course.module ocuda.module], ,[build_cuda=no])

AC_MSG_CHECKING([whether to build cuda code])
AC_MSG_RESULT($build_cuda)

AM_CONDITIONAL([BUILD_CUDA], [test $build_cuda = yes])

AC_OUTPUT([Makefile])

