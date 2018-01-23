class Collatz
  def initialize(len = 0)
    @cache = Array(UInt32).new(len, 0_u32)
  end

  def length(num : UInt32)
    return 1 if num <= 1
    return @cache[num - 2] if @cache[num - 2]? && @cache[num - 2] != 0

    len = 1_u32
    if num.odd?
      len += length(num * 3 + 1)
    else
      len += length(num / 2)
    end

    if (num - 2) < @cache.size
      @cache[num - 2] = len
    end

    len
  end
end
