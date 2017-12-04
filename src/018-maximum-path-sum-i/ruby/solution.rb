module Solution
  def self.solve triangle
    while triangle.length > 1
      triangle = reduce triangle
    end

    triangle[0][0]
  end

  def self.reduce triangle
    upper = triangle[0..-3]
    lower = triangle[-2..-1]

    upper << lower[0].each_with_index.map do |n, i|
      if lower[1][i] > lower[1][i+1]
        n + lower[1][i]
      else
        n + lower[1][i+1]
      end
    end
  end
end
