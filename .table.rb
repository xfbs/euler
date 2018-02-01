require 'json'
data = JSON.load(File.read(ARGV[0]))
lang = data.map{|p, i| i.map{|l, t| l}}.flatten.uniq
lang = lang.sort_by{|l| data.values.map{|i| i.keys}.flatten.count{|i| i == l}}
lang = lang.reverse

puts "| problem | #{lang.map{|l| l.rjust(3, ' ')}.join(' | ')} | *avg* |"
puts "| ------: | #{lang.map{|l| l.rjust(3, ' ').gsub(/./, '-')}.join(' | ')} | ----- |"

data.keys.each do |key|
  avg = data[key].values.inject(0, :+) / data[key].values.length
  puts "| [`#{key}`](https://projecteuler.net/problem=#{key}) | #{lang.map{|l| (if data[key][l] then "#{data[key][l]}ms" else "" end).to_s.rjust(4, ' ')}.join(' | ')} | #{avg}ms |"
end

avgs = lang.map do |l|
  res = data.values.map{|i| i[l]}.compact
  res.inject(0, :+) / res.length
end

all_numbers = data.values.map{|p| p.values}.flatten
global_avg = all_numbers.inject(0, &:+) / all_numbers.length
all_numbers.sort!
global_mean = all_numbers[all_numbers.length]

means = lang.map do |l|
  res = data.values.map{|i| i[l]}.compact
  res.sort!
  res[res.length/2]
end

mins = lang.map do |l|
  data.values.map{|i| i[l]}.compact.min
end

maxs = lang.map do |l|
  data.values.map{|i| i[l]}.compact.max
end

puts "| *min* | #{mins.join('ms | ')}ms | #{mins.min}ms |"
puts "| *max* | #{maxs.join('ms | ')}ms | #{maxs.max}ms |"
puts "| *average* | #{avgs.join('ms | ')}ms | #{global_avg}ms |"
puts "| *mean* | #{means.join('ms | ')}ms | #{global_mean}ms |"

counts = lang.map{|l| data.values.map{|i| i.keys}.flatten.count{|i| i == l}}
puts "| *count* | #{counts.join(' | ')} | #{counts.inject(0, :+)} |"

