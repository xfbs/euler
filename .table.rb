require 'json'
data = JSON.load(File.read(ARGV[0]))
lang = data.map{|p, i| i.map{|l, t| l}}.flatten.uniq
lang = lang.sort_by{|l| data.values.map{|i| i.keys}.flatten.count{|i| i == l}}
lang = lang.reverse

puts "| problem | #{lang.map{|l| l.rjust(3, ' ')}.join(' | ')} | *avg* |"
puts "| ------- | #{lang.map{|l| l.rjust(3, ' ').gsub(/./, '-')}.join(' | ')} | ----- |"

data.keys.each do |key|
  avg = data[key].values.inject(0, :+) / data[key].values.length
  puts "| [`#{key}`](https://projecteuler.net/problem=#{key}) | #{lang.map{|l| (if data[key][l] then "#{data[key][l]}ms" else "" end).to_s.rjust(4, ' ')}.join(' | ')} | #{avg} |"
end

counts = lang.map{|l| data.values.map{|i| i.keys}.flatten.count{|i| i == l}}
puts "| *count* | #{counts.join(' | ')} | #{counts.inject(0, :+) / counts.length} |"

avgs = lang.map do |l|
  res = data.values.map{|i| i[l]}.compact
  res.inject(0, :+) / res.length
end
puts "| *average* | #{avgs.join(' | ')} | #{avgs.inject(0, :+) / avgs.length} |"
