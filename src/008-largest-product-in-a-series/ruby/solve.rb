#!/usr/bin/env ruby
require_relative 'solution'

raise "no data file specified" unless ARGV[0]

puts Solution.solve(ARGV[0], 13)
