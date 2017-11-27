module Solution
  def self.solve n
    # your code goes here
    return n
  end

  def self.rects width, height
    height_poss = ((height + 1) * (height/2.0)).to_i
    width_poss  = ((width  + 1) * (width/2.0)).to_i

    height_poss * width_poss
  end
end
