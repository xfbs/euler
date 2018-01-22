require "minitest/autorun"
require "../src/euler/palindrome"

class PalindromeTest < Minitest::Test
  def test_is_palindrome
    assert Euler.is_palindrome?(1)
  end
end
