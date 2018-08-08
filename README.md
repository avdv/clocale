# clocale [![travis-badge][]][travis] [![appveyor-badge][]][appveyor]

[travis]:         https://travis-ci.org/avdv/clocale
[travis-badge]:   https://travis-ci.org/avdv/clocale.svg?branch=master
[appveyor]:       https://ci.appveyor.com/project/avdv/clocale/branch/master
[appveyor-badge]: https://ci.appveyor.com/api/projects/status/l7pp3mjqvocb2n9r/branch/master?svg=true

This Ruby extension provides access to the C library's `setlocale`, `strxfrm`
and `strcoll` functions which are inherently useful for proper sorting
(collation) of strings.

This extension is quite similar to https://github.com/k3rni/ffi-locale but
does not use FFI because the `LC_*` constants are not stable across different C
libraries.
