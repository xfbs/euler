require "spec"
require "../src/euler/prime"

describe "Euler::Prime" do
  describe "nth" do
    it "should produce the correct result" do
      p = Euler::Prime.new

      p.nth(0).should eq 2
      p.nth(1).should eq 3
      p.nth(2).should eq 5
      p.nth(3).should eq 7
      p.nth(4).should eq 11
      p.nth(5).should eq 13
      p.nth(6).should eq 17
      p.nth(7).should eq 19
    end
  end

  describe "next" do
    it "should produce the correct result" do
      p = Euler::Prime.new

      p.next.should eq 5
      p.next.should eq 7
      p.next.should eq 11
      p.next.should eq 13
      p.next.should eq 17
      p.next.should eq 19
      p.next.should eq 23
    end
  end

  describe "iter" do
    it "should produce the correct result" do
      p = Euler::Prime.new

      p.iter.first(5).to_a.should eq [2, 3, 5, 7, 11]
      p.iter.first(2).to_a.should eq [2, 3]
      p.iter.first(8).to_a.should eq [2, 3, 5, 7, 11, 13, 17, 19]
    end
  end

  describe "check" do
    it "should produce the correct result" do
      p = Euler::Prime.new

      p.check?(2).should eq true
      p.check?(3).should eq true
      p.check?(4).should eq false
      p.check?(5).should eq true
      p.check?(6).should eq false
      p.check?(7).should eq true
      p.check?(8).should eq false
      p.check?(9).should eq false
    end
  end

  describe "index" do
    it "should produce the correct result" do
      p = Euler::Prime.new

      p.index(0).should be_nil
      p.index(1).should be_nil
      p.index(2).should eq 0
      p.index(3).should eq 1
      p.index(4).should be_nil
      p.index(5).should eq 2
      p.index(6).should be_nil
      p.index(7).should eq 3
      p.index(8).should be_nil
      p.index(9).should be_nil
      p.index(11).should eq 4
      p.index(13).should eq 5
      p.index(17).should eq 6
    end
  end
end
