class Collatz
  def initialize(len = 0)
    @cache = Array.new(len)
  end

  def length(num)
    return 1 if num == 1
    return 2 if num == 2
    odd = num.odd?
    return @cache[(num - 3) / 2] if odd && @cache[(num - 3) / 2]

    step = 1
    succ = num
    if odd
      succ = 3 * succ + 1
    else
      succ /= 2
    end

    while succ.even?
      succ /= 2
      step += 1
    end

    len = step + length(succ)
    @cache[(num - 3) / 2] = len if odd && ((num - 3) / 2) < @cache.length

    len
  end
end
