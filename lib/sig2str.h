/* sig2str.h -- convert between signal names and numbers

   Copyright (C) 2002, 2005, 2009-2024 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Written by Paul Eggert.  */

/* This file uses HAVE_* macros.  */
# if !_GL_CONFIG_H_INCLUDED
#  error "Please include config.h first."
# endif

#include <signal.h>

/* Maximum size of a signal name returned by sig2str(), including the
   terminating NUL byte.  */
#ifndef SIG2STR_MAX
/* The longest one: "RTMAX", then "+" or "-", then up to 10 digits, then NUL.
   Add + 2 as a reserve for the future.  */
# define SIG2STR_MAX (5 + 1 + 10 + 1 + 2)
#endif

#ifndef HAVE_SIG2STR
int sig2str (int, char *);
#endif
#ifndef HAVE_STR2SIG
int str2sig (char const *, int *);
#endif

/* An upper bound on signal numbers allowed by the system.  */

#if defined _sys_nsig
# define SIGNUM_BOUND (_sys_nsig - 1)
#elif defined _SIG_MAXSIG
# define SIGNUM_BOUND (_SIG_MAXSIG - 2) /* FreeBSD >= 7.  */
#elif defined NSIG
# define SIGNUM_BOUND (NSIG - 1)
#else
# define SIGNUM_BOUND 64
#endif
