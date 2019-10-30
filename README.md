# clocale [![rubygem-badge][]][rubygem] [![travis-badge][]][travis] [![appveyor-badge][]][appveyor] [![codecov-badge][]][codecov] [![dependabot-b][]][dependabot]

[rubygem]:        https://badge.fury.io/rb/clocale
[rubygem-badge]:  https://badge.fury.io/rb/clocale.svg
[travis]:         https://www.travis-ci.com/avdv/clocale
[travis-badge]:   https://www.travis-ci.com/avdv/clocale.svg?branch=master
[appveyor]:       https://ci.appveyor.com/project/avdv/clocale/branch/master
[appveyor-badge]: https://ci.appveyor.com/api/projects/status/l7pp3mjqvocb2n9r/branch/master?svg=true
[codecov]:        https://codecov.io/gh/avdv/clocale
[codecov-badge]:  https://codecov.io/gh/avdv/clocale/branch/master/graph/badge.svg
[dependabot]:     https://dependabot.com
[dependabot-b]:   https://api.dependabot.com/badges/status?host=github&repo=avdv/clocale

This Ruby extension provides access to the C library's `setlocale`, `strxfrm`
and `strcoll` functions which are inherently useful for proper sorting
(collation) of strings.

This extension is quite similar to https://github.com/k3rni/ffi-locale but
does not use FFI because the `LC_*` constants are not stable across different C
libraries.
