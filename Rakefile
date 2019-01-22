# frozen_string_literal: true

require 'rake/extensiontask'
require 'rubygems/tasks'

Gem::Tasks.new

require 'rspec/core/rake_task'
RSpec::Core::RakeTask.new

require 'rubocop/rake_task'
RuboCop::RakeTask.new

Rake::ExtensionTask.new 'clocale' do |ext|
  ext.lib_dir = 'lib/clocale'
end

# simple sanity check:

task test: %w[compile] do
  ruby '-Ilib', '-rclocale', '-e', 'p CLocale.setlocale(CLocale::LC_ALL, "")'
end

task spec: :compile
task default: %i[spec rubocop]
