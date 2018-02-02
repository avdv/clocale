Gem::Specification.new do |spec|
  spec.name          = 'clocale'
  spec.version       = '0.0.3'
  spec.authors       = ['Claudio Bley']
  spec.email         = ['claudio.bley@gmail.com']
  spec.summary       = "A Ruby gem that wraps C locale functions."
  spec.homepage      = 'https://github.com/avdv/clocale'
  spec.license       = 'MIT'

  spec.extensions = %w[ext/clocale/extconf.rb]

  spec.files = `git ls-files -z`.split("\x0").reject do |f|
    f.match(%r{^.gitignore})
  end

  spec.add_development_dependency 'rake', '~> 12.3'
  spec.add_development_dependency 'rake-compiler', '~> 1.0'
  spec.add_development_dependency 'rspec', '~> 3.7'
  spec.add_development_dependency 'rubygems-tasks', '~> 0.2'
end
