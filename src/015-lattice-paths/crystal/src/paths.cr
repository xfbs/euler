class Paths
  def initialize(x : UInt32, y : UInt32)
    max_x = [x, y].min + 1_u32
    max_y = [x, y].max + 1_u32
    @count = Array(Array(UInt64)).new(max_x){Array(UInt64).new(max_y, 0_u64)}
  end

  def count(_x : UInt32, _y : UInt32)
    x, y = [_x, _y].sort

    # known shortcuts
    return 1_u64 if x == 0
    return 1_u64+y if x == 1
    return (1_u64+y)*(y+2)/2 if x == 2

    return @count[x][y] if @count[x]? && @count[x][y] != 0

    result = count(x-1, y) + count(x, y-1)
    @count[x][y] = result if @count[x]?

    result
  end
end
