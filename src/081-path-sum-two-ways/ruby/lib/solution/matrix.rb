require 'solution/cell'

module Solution
  class Matrix
    def initialize grid
      @grid = (0..grid.length-1).zip(grid).map do |rowc, row|
        (0..row.length-1).zip(row).map do |colc, cell|
          Cell.new(self, rowc, colc, cell)
        end
      end
    end

    def get row, col
      if @grid[row]
        @grid[row][col]
      end
    end
  end
end
