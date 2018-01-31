#!/bin/bash
# script to update xfbs.github.io/euler

# stop if something fails
set -e

# clone into euler
if [ ! -d "euler" ]; then
  git clone https://github.com/xfbs/euler
fi

cd euler
git pull
cd ..

# copy readme, contributing, progress
echo "# About" > index.md
tail -n+2 euler/readme.md >> index.md
cp euler/contributing.md contributing.md
cp euler/progress.md progress.md
git add index.md contributing.md progress.md

# generate docs for lib/c
cd euler/lib/c
make doc
cd ../../../
rm -rf docs/c
cp -r euler/doc/lib/c/html docs/c
git add docs/c

# generate docs for lib/crystal
cd euler/lib/crystal/euler
make doc
cd ../../../../
rm -rf docs/crystal
cp -r euler/doc/lib/crystal docs/crystal
git add docs/crystal

# generate docs for lib/rust
cd euler/lib/rust/euler
make doc
cd ../../../../
rm -rf docs/rust
cp -r euler/doc/lib/rust docs/rust
git add docs/rust

git commit -m "updates documentation"
echo "all done, ready to push!"
