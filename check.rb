
puts Encoding.find('filesystem')

arg = ARGV[0]
puts arg
@name = File.basename(arg)
@stats = File.lstat(arg)

if @stats.directory?
  @contents = Dir.entries(arg)

  @contents.each do |item|
    puts "#{item}: #{File.lstat(File.join(arg, item)).size}"
  rescue => e
    warn "#{item}: #{e}"
  end
end

