#!/usr/bin/env ruby
require 'fileutils'

BASEDIR = "../src"

problems = Dir["#{BASEDIR}/???-*"].map do |n|
  [n.scan(/\d\d\d/)[0].to_i, n]
end[0..60]

# fix up problems
problem_md = problems.map{|n| File.open("#{n[1]}/problem.md").read}
problem_md = problem_md.map do |p|
  p.gsub(/^# /, "## ")
end

# fix up explanations
explain_md = problems.map do |n|
  if File.exist?("#{n[1]}/explain.md")
    File.open("#{n[1]}/explain.md").read
  else
    nil
  end
end
explain_md = explain_md.map do |p|
  (p || "").gsub(/^# /, "### ")
end

problem_md = problem_md.zip(explain_md).map{|n| n.join("\n\n")}
problem_md = problem_md.join("\n\n\\clearpage\n\n")

problems.each do |p|
  Dir["#{p[1]}/*.gif"].each do |g|
    FileUtils.cp(g, ".")
  end
end

File.open("problems.md", "w").write(problem_md)

`pandoc --latex-engine=xelatex -o problems.pdf problems.md`
`rm *.gif`
