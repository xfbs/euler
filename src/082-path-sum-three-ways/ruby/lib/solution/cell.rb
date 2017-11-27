module Solution
  class Cell
    attr_reader :row, :col, :cell

    def initialize matrix, row, col, cell
      @matrix = matrix
      @row    = row
      @col    = col
      @cell   = cell
      @path   = {}
    end

    def right
      @matrix.get(row, col+1)
    end

    def down
      @matrix.get(row+1, col)
    end

    def up
      @matrix.get(row-1, col)
    end

    def min_path dir=:best
      return @cell if !right
      return @path[dir] if @path[dir]

      # find out the minimum paths in all directions
      @path[:right] = @cell + right.min_path()
      @path[:down]  = down && (@cell + down.min_path(:down)) unless dir == :up
      @path[:up]    = up && (@cell + up.min_path(:up)) unless dir == :down

      # if going right is shorter than going into that direction,
      # update the path length
      (dir == :best && [:down, :up] || [dir]).each do |d|
        @path[d] = [@path[d], @path[:right]].compact.min
      end

      # find the optimal path if we have all three directions
      @path[:best] = @path.values.min if @path.values.length == 3

      @path[dir]
    end
  end
end
