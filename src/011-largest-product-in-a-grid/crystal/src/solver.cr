module Solver
  def self.solve(grid)
    [[1,0], [0,1], [1,1], [-1,1]].map do |d|
      quadruple_products(grid, d[0], d[1]).map{|r| r.max}.max
    end.max
  end

  def self.quadruple_products(grid, dir_x, dir_y)
    lim_y = [0, -1-dir_y, 0, -1-2*dir_y]
    lim_y = [-dir_y, -1, -2*dir_y, -1] if dir_y < 0
    lim_x = [0, -1-dir_x, 0, -1-2*dir_x]
    lim_x = [-dir_x, -1, -2*dir_x, -1] if dir_x < 0

    tuples = grid[lim_y[0]..lim_y[1]].each_with_index.map do |t|
      row, y = t
      row[lim_x[0]..lim_x[1]].each_with_index.map do |r|
        cell, x = r
        cell * grid[y+dir_y+lim_y[0]][x+dir_x+lim_x[0]]
      end.to_a
    end.to_a

    tuples[lim_y[2]..lim_y[3]].each_with_index.map do |t|
      row, y = t
      row[lim_x[2]..lim_x[3]].each_with_index.map do |r|
        cell, x = r
        cell * tuples[y+2*dir_y+lim_y[2]][x+2*dir_x+lim_x[2]]
      end.to_a
    end.to_a
  end
end
