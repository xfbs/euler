#!/usr/bin/env ruby
require_relative 'solution'

throw "no data file supplied" unless ARGV[0]
names = File.open(ARGV[0]).read
puts Solution.solve(names.split(',').map{|n| n[1..-2]})
