require 'mkmf'

def check_functions
  %w[setlocale strcoll strxfrm].each do |func|
    abort "missing function `#{ func }``" unless have_func func
  end
end

abort 'missing `locale.h`' unless have_header 'locale.h'

check_functions

create_makefile 'clocale/clocale'
