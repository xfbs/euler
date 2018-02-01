require "spec"
require "../src/euler/sieve"

describe "Euler::Sieve" do
  it "should sieve small numbers" do
    Euler::Sieve.new(10).to_a.should eq [2, 3, 5, 7]
    Euler::Sieve.new(15).to_a.should eq [2, 3, 5, 7, 11, 13]
    Euler::Sieve.new(25).to_a.should eq [2, 3, 5, 7, 11, 13, 17, 19, 23]
  end

  it "should sieve big numbers" do
    Euler::Sieve.new(100).size.should eq 25
    Euler::Sieve.new(1000).size.should eq 168
    Euler::Sieve.new(10000).size.should eq 1229
  end
end
