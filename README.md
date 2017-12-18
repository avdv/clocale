# clocale

[![Build 
status](https://ci.appveyor.com/api/projects/status/l7pp3mjqvocb2n9r/branch/master?svg=true)](https://ci.appveyor.com/project/avdv/clocale/branch/master)

This Ruby extension provides access to the C library's `setlocale`, `strxfrm`
and `strcoll` functions which are inherently useful for proper sorting
(collation) of strings.

This extension is quite similar to https://github.com/k3rni/ffi-locale but
does not use FFI because the `LC_*` constants are not stable across different C
libraries.
