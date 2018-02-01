//! # Euler
//!
//! This crate is part of [xfbs/euler](https://xfbs.github.io/euler), which aims
//! to solve [Project Euler](https://projecteuler.net/) problems in a variety of
//! languages.
//!
//! The functions and traits of this crate are sharedbetween solutions
//! solutions and implement generic, reusable algorithms. Tests should be
//! available for all functions.
//!
//! If you clone the [repository](https://github.com/xfbs/euler), and navigate
//! to this library (which is in `/lib/rust/euler`), there is a `Makefile` that
//! supports the following targets:
//!
//!   - `make test` to build and run all the tests of this library.
//!
//!   - `make fmt` to run the crystal code formatter over all of the code in
//!      this library.
//!
//!   - `make doc` to generates these docs. The output will be placed in
//!     `/doc/lib/rust` in the repository.
//!
//! All code in this library has been developed and tested with Rust `1.22.1`.
//! Since rust is still under development, things may break with future releases
//! of the compiler.

mod math;
mod prime;
mod sieve;
mod divisors;
mod rotations;
mod digits;
mod palindrome;
mod permutations;

pub use math::Gcd;
pub use math::Lcm;
pub use math::factorial;
pub use prime::Prime;
pub use sieve::Sieve;
pub use digits::ToDigits;
pub use digits::Digits;
pub use palindrome::IsPalindrome;
pub use palindrome::ToPalindrome;
pub use rotations::ToRotations;
pub use rotations::Rotations;
pub use divisors::ToDivisors;
pub use permutations::permutations;
pub use permutations::Permutations;
