require 'rake/extensiontask'
require 'rubygems/tasks'

Gem::Tasks.new

Rake::ExtensionTask.new 'clocale' do |ext|
  ext.lib_dir = 'lib/clocale'
end

# simple sanity check:

task test: %w[compile] do
  ruby '-Ilib', '-rclocale', '-e', 'p CLocale.setlocale(CLocale::LC_ALL, "")'
end

task default: :test
