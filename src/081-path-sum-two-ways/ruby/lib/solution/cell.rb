module Solution
  class Cell
    attr_reader :row, :col, :cell

    def initialize(matrix, row, col, cell)
      @matrix = matrix
      @row    = row
      @col    = col
      @cell   = cell
    end

    def right
      @matrix.get(row, col + 1)
    end

    def down
      @matrix.get(row + 1, col)
    end

    def min_path_sum
      return @path if @path
      down_path = down.min_path_sum if down
      right_path = right.min_path_sum if right

      @path = if !right_path && !down_path
                @cell
              elsif !right_path
                @cell + down_path
              elsif !down || right_path < down_path
                @cell + right_path
              else
                @cell + down_path
              end
    end
  end
end
