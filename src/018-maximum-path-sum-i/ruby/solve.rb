#!/usr/bin/env ruby
require_relative 'solution'

throw "no datafile specified" if ARGV.length < 1
triangle = File.open(ARGV[0]).read.split("\n").map{|l| l.split(" ").map{|e| e.to_i}}
puts Solution.solve(triangle)
