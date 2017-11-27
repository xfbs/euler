require 'solution/matrix'

module Solution
  def self.solve file
    f = File.open(file, 'r').read
    mat = f.chomp.split("\n").map do |line|
      line.split(',').map do |cell|
        cell.to_i
      end
    end

    matrix = Matrix.new mat
    matrix.get(0, 0).min_path_sum
  end
end
