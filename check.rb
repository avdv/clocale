
puts Encoding.find('filesystem')

arg = ARGV[0]
puts arg
@name = File.basename(arg)
@stats = File.lstat(arg)

if @stats.directory?
  begin
    @contents = Dir.entries(arg, encoding: Encoding::UTF_16)

    @contents.each do |item|
      puts "#{item.encode(Encoding.default_external)}: #{File.lstat(File.join(arg, item)).size}"
    rescue => e
      warn "#{item}: #{e}"
    end
  rescue StandardError => e
    puts "#{e}: #{e.backtrace}"
  end
end

