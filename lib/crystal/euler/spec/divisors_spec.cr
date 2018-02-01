require "spec"
require "../src/euler/divisors"

describe "Euler" do
  describe "divisors" do
    it "should exist and be a method" do
      Euler.divisors(5).should_not be_nil
    end

    it "should return a Euler::Divisors instance" do
      Euler.divisors(9.to_i32).class.should eq(Euler::Divisors(Int32))
    end

    it "should return the correct divisors" do
      Euler.divisors(1).sum.should eq 1
      Euler.divisors(2).sum.should eq 1
      Euler.divisors(3).sum.should eq 1
      Euler.divisors(4).sum.should eq 3
      Euler.divisors(5).sum.should eq 1
      Euler.divisors(6).sum.should eq 6

      Euler.divisors(4).to_a.sort.should eq [1, 2]
      Euler.divisors(12).to_a.sort.should eq [1, 2, 3, 4, 6]
    end
  end
end

describe "Euler::Divisors" do
  it "should return the correct divisors" do
    Euler::Divisors.new(1).to_a.sort.should eq [1]
    Euler::Divisors.new(2).to_a.sort.should eq [1]
    Euler::Divisors.new(3).to_a.sort.should eq [1]
    Euler::Divisors.new(4).to_a.sort.should eq [1, 2]
    Euler::Divisors.new(5).to_a.sort.should eq [1]
    Euler::Divisors.new(6).to_a.sort.should eq [1, 2, 3]
    Euler::Divisors.new(7).to_a.sort.should eq [1]
    Euler::Divisors.new(8).to_a.sort.should eq [1, 2, 4]
    Euler::Divisors.new(9).to_a.sort.should eq [1, 3]
    Euler::Divisors.new(10).to_a.sort.should eq [1, 2, 5]
    Euler::Divisors.new(11).to_a.sort.should eq [1]
    Euler::Divisors.new(12).to_a.sort.should eq [1, 2, 3, 4, 6]
    Euler::Divisors.new(60).to_a.sort.should eq [1, 2, 3, 4, 5, 6, 10, 12, 15,
                                                 20, 30]
  end
end
