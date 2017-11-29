About
------

This Ruby extension provides access to the C library's `setlocale`, `strxfrm`
and `strcoll` functions which are inherently useful for proper sorting
(collation) of strings.

This extension is quite similar to https://github.com/seanohalpin/ffi-locale but
does not use FFI because the `LC_*` constants are not stable across different C
libraries.
