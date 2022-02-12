# clocale [![rubygem-badge][]][rubygem] [![github-badge][]][workflow] [![appveyor-badge][]][appveyor] [![codecov-badge][]][codecov]

[rubygem]:        https://badge.fury.io/rb/clocale
[rubygem-badge]:  https://badge.fury.io/rb/clocale.svg
[workflow]:       https://github.com/avdv/clocale/actions/workflows/test.yml
[github-badge]:   https://github.com/avdv/clocale/actions/workflows/test.yml/badge.svg
[appveyor]:       https://ci.appveyor.com/project/avdv/clocale/branch/master
[appveyor-badge]: https://ci.appveyor.com/api/projects/status/l7pp3mjqvocb2n9r/branch/master?svg=true
[codecov]:        https://codecov.io/gh/avdv/clocale
[codecov-badge]:  https://codecov.io/gh/avdv/clocale/branch/master/graph/badge.svg

This Ruby extension provides access to the C library's `setlocale`, `strxfrm`
and `strcoll` functions which are inherently useful for proper sorting
(collation) of strings.

This extension is quite similar to https://github.com/k3rni/ffi-locale but
does not use FFI because the `LC_*` constants are not stable across different C
libraries.
