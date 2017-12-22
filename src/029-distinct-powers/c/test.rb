s = {}

(2..100).each do |a|
  (2..100).each do |b|
    p = a**b
    if s[p]
      puts "#{s[p].join('**')} == #{a}**#{b}"
    else
      s[p] = [a, b]
    end
  end
end
