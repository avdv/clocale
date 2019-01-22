# frozen_string_literal: true

# rubocop:disable Metrics/BlockLength
Gem::Specification.new do |spec|
  CLOCALE_VERSION = '0.0.4'

  is_tagged = ENV['TRAVIS_TAG'] == "v#{CLOCALE_VERSION}"
  is_origin = ENV['TRAVIS_REPO_SLUG'] == 'avdv/clocale'
  job_number = ENV['TRAVIS_JOB_NUMBER']

  spec.name          = 'clocale'
  spec.version       = if job_number && is_origin && !is_tagged
                         # Prereleasing on Travis CI
                         digits = CLOCALE_VERSION.to_s.split '.'
                         digits[-1] = digits[-1].to_s.succ

                         digits.join('.') + ".alpha.#{ENV['TRAVIS_JOB_NUMBER']}"
                       else
                         CLOCALE_VERSION
                       end
  spec.authors       = ['Claudio Bley']
  spec.email         = ['claudio.bley@gmail.com']
  spec.summary       = 'A Ruby gem that wraps C locale functions.'
  spec.homepage      = 'https://github.com/avdv/clocale'
  spec.license       = 'MIT'

  spec.required_ruby_version = '>= 2.3'

  spec.extensions = %w[ext/clocale/extconf.rb]

  spec.files = `git ls-files -z`.split("\x0").reject do |f|
    f.match(/^.gitignore/)
  end

  spec.add_development_dependency 'codecov', '~> 0.1.10'
  spec.add_development_dependency 'rake', '~> 12.3.1'
  spec.add_development_dependency 'rake-compiler', '~> 1.0.5'
  spec.add_development_dependency 'rspec', '~> 3.8.0'
  spec.add_development_dependency 'rubocop', '~> 0.63.0'
  spec.add_development_dependency 'rubocop-rspec', '~> 1.31.0'
  spec.add_development_dependency 'rubygems-tasks', '~> 0.2.4'
end
# rubocop:enable Metrics/BlockLength
