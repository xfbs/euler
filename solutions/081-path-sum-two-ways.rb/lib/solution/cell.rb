module Solution
  class Cell
    attr_reader :row, :col, :cell

    def initialize matrix, row, col, cell
      @matrix = matrix
      @row    = row
      @col    = col
      @cell   = cell
    end

    def right
      @matrix.get(row, col+1)
    end

    def down
      @matrix.get(row+1, col)
    end

    def min_path_sum
      return @path if @path
      down_path = down.min_path_sum if down
      right_path = right.min_path_sum if right

      if !right_path && !down_path
        @path = @cell
      elsif !right_path
        @path = @cell + down_path
      elsif !down || right_path < down_path
        @path = @cell + right_path
      else
        @path = @cell + down_path
      end
    end
  end
end
