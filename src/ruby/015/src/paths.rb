class Paths
  def initialize(x, y)
    max_x = [x, y].min + 1
    max_y = [x, y].max + 1
    @count = Array.new(max_x) { Array.new(max_y) }
  end

  def count(_x, _y)
    x, y = [_x, _y].sort

    # known shortcuts
    return 1 if x == 0
    return y + 1 if x == 1
    return (y + 1) * (y + 2) / 2 if x == 2

    return @count[x][y] if @count[x][y]

    result = count(x - 1, y) + count(x, y - 1)
    @count[x][y] = result if @count[x]

    result
  end
end
