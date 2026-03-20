#!/usr/bin/env bash

sed -i '' '/^FFLAGS =/ s/$/ -fallow-argument-mismatch/' makefile