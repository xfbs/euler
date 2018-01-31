#!/bin/bash
set -e
for i in *_test; do
  ./$i
done
