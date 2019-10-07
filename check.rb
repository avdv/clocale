
puts Encoding.find('filesystem')

arg = ARGV[0]
puts arg
@name = File.basename(arg)
@stats = File.lstat(arg)

if @stats.directory?
  @contents = Dir.entries(arg)

  @contents.each do |e|
    puts e, File.lstat(File.join(arg, e)).size
  end
end

