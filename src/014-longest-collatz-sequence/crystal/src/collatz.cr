class Collatz
  def initialize(len=0)
    @cache = Array(UInt32 | Nil).new(len, nil)
  end

  def length(num : UInt32)
    return 1_u32 if num == 1
    return 2_u32 if num == 2
    odd = (num % 2) == 1
    return @cache[(num-3)/2].as(UInt32) if odd && @cache[(num-3)/2]?

    step = 1_u32
    succ = num
    if odd
      succ = (3_u32*succ + 1_u32).as(UInt32)
    else
      succ /= 2
    end

    while (succ % 2) == 0
      succ /= 2
      step += 1
    end

    len = step + length(succ)
    if odd && ((num-3)/2) < @cache.size
      @cache[(num-3)/2] = len
    end

    len.as(UInt32)
  end
end
