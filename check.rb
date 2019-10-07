
puts Encoding.find('filesystem')
puts Encoding.default_external
puts Encoding.default_internal

arg = ARGV[0]
puts arg
@name = File.basename(arg)
@stats = File.lstat(arg)

if @stats.directory?
  begin
    @contents = Dir.entries(arg, encoding: Encoding::UTF_8)

    @contents.each do |item|
      puts "#{item.encode(Encoding.default_external, Encoding::UTF_8)}: #{File.lstat(File.join(arg, item)).size}"
    rescue => e
      warn "#{item}: #{e}"
    end
  rescue StandardError => e
    puts "#{e}: #{e.backtrace}"
  end
end

