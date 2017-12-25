require 'json'
data = JSON.load(File.read(ARGV[0]))
lang = data.map{|p, i| i.map{|l, t| l}}.flatten.uniq
lang = lang.sort_by{|l| data.values.map{|i| i.keys}.flatten.count{|i| i == l}}
lang = lang.reverse

puts "| problem | #{lang.map{|l| l.rjust(3, ' ')}.join(' | ')} |"
puts "| ------- | #{lang.map{|l| l.rjust(3, ' ').gsub(/./, '-')}.join(' | ')} |"

data.keys.each do |key|
  puts "| `#{key}` | #{lang.map{|l| (data[key][l] || "").to_s.rjust(4, ' ')}.join(' | ')} |"
end
