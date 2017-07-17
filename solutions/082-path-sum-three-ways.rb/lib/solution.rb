require 'solution/matrix'

module Solution
  def self.solve file
    f = File.open(file, 'r').read
    mat = f.chomp.split("\n").map do |line|
      line.split(',').map do |cell|
        cell.to_i
      end
    end

    # we can start from any cell on the right,
    # so we gotta check 'em all.
    matrix = Matrix.new mat
    paths = []
    matrix.each_row do |row|
      paths << row[0].min_path
    end

    paths.min
  end
end
