require "spec"
require "../src/euler/math"

describe "Euler" do
  describe "factorial" do
    it "should produce the correct result" do
      Euler.factorial(0).should eq(1u64)
      Euler.factorial(1).should eq(1u64)
      Euler.factorial(2).should eq(1u64*2)
      Euler.factorial(3).should eq(1u64*2*3)
      Euler.factorial(4).should eq(1u64*2*3*4)
      Euler.factorial(5).should eq(1u64*2*3*4*5)
      Euler.factorial(6).should eq(1u64*2*3*4*5*6)
      Euler.factorial(7).should eq(1u64*2*3*4*5*6*7)
    end
  end

  describe "palindrome" do
    it "should produce the correct result" do
      Euler.is_palindrome?(1).should be_true
      Euler.is_palindrome?(10201).should be_true
      Euler.is_palindrome?(209902).should be_true
      Euler.is_palindrome?(5, 2).should be_true
      Euler.is_palindrome?(1234).should be_false
      Euler.is_palindrome?(1121).should be_false
      Euler.is_palindrome?(101102).should be_false
      Euler.is_palindrome?(32).should be_false
    end
  end

  describe "fibonacci" do
    it "should produce the correct result" do
      Euler.fibonacci(1).should eq 1
      Euler.fibonacci(2).should eq 1
      Euler.fibonacci(3).should eq 2
      Euler.fibonacci(4).should eq 3
      Euler.fibonacci(5).should eq 5
      Euler.fibonacci(6).should eq 8
      Euler.fibonacci(7).should eq 13
      Euler.fibonacci(8).should eq 21
      Euler.fibonacci(9).should eq 34
      Euler.fibonacci(10).should eq 55
    end
  end

  describe "pandigital" do
    it "should work with pandigitals of length one" do
      Euler.pandigital(len: 1, nth: 0).should eq 1
    end

    it "should work with pandigitals of length two" do
      Euler.pandigital(len: 2, nth: 0).should eq 12
      Euler.pandigital(len: 2, nth: 1).should eq 21
    end

    it "should work with pandigitals of length three" do
      Euler.pandigital(len: 3, nth: 0).should eq 123
      Euler.pandigital(len: 3, nth: 1).should eq 132
      Euler.pandigital(len: 3, nth: 2).should eq 213
      Euler.pandigital(len: 3, nth: 3).should eq 231
      Euler.pandigital(len: 3, nth: 4).should eq 312
      Euler.pandigital(len: 3, nth: 5).should eq 321
    end

    it "should work with pandigitals of length five" do
      Euler.pandigital(len: 5, nth: 0).should eq 12345
      Euler.pandigital(len: 5, nth: 1).should eq 12354
      Euler.pandigital(len: 5, nth: 2).should eq 12435
      Euler.pandigital(len: 5, nth: 3).should eq 12453
      Euler.pandigital(len: 5, nth: 4).should eq 12534
      Euler.pandigital(len: 5, nth: 5).should eq 12543
    end

    it "should work with pandigitals of length nine" do
      Euler.pandigital(len: 9, nth: 0).should eq 123456789
      Euler.pandigital(len: 9, nth: 362879).should eq 987654321
    end
  end
end
