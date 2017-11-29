Gem::Specification.new do |spec|
  spec.name          = 'clocale'
  spec.version       = '0.0.1'
  spec.authors       = ['Claudio Bley']
  spec.email         = ['claudio.bley@gmail.com']
  spec.summary       = "A Ruby gem that wraps C locale functions."
  spec.homepage      = 'https://github.com/avdv'
  spec.license       = 'MIT'

  spec.extensions = %w[ext/clocale/extconf.rb]

  spec.files = %w[
    MIT-LICENSE
    Rakefile
    ext/clocale/extconf.rb
    ext/clocale/clocale.c
    lib/clocale.rb
  ]

  spec.add_development_dependency 'rake'
  spec.add_development_dependency 'rake-compiler'
  spec.add_development_dependency 'rubygems-tasks'
end
