mpa - The Mass Patch Applier 
================================
[![Build Status](https://travis-ci.org/frap129/mpa.svg?branch=0.1)](https://travis-ci.org/frap129/mpa)
What is mpa?
------------
mpa is a tool written in C, made for applying many patch files
at once. This is acheived by searching a defined directory for
.patch files.

How do I build mpa?
-------------------
It's as simple as running "make mpa"! The only compilation
dependencies are gcc and automake, which are standard for
almost all linux programs.

How do I use mpa?
-----------------
mpa is easy to use, only requiring one argument. Simply cd into
the directory of the source you want to patch, and run 
  mpa /patch/directory/
to apply all patch files in /patch/directory/ and all sub
directories of /patch/directory/.

