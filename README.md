Notepush
====================================

Command line tool that pushes notes to git. I made this so that I could quickly take notes from the command line without disrupting my work flow. 


Examples
=======



```console
foo@bar:~$ psh A profound hockey related thought @hockey
foo@bar:-$ psh Wayne Gretzky played for edmonton @hockey @edmonton
foo@bar:-$ psh -o Another note # all local changes are pushed to remote due to '-o' option.
```

Installation 
==========================

Dependencies
------------

- [CMake] build system version 3.11+;
- C++17 compiler (i.e. [GCC] 9+) - std::filesystem is required.
- [libgit2] tested with v0.28.4

Before You Start
------------
1. Create a git repository on your local machine (or clone and existing one).
2. Set the write permissions of this directory so that notepush can read/write it.

Installation on Linux
---------------------

    $ git clone https://github.com/adamfill28/Notepush
    $ mkdir build && cd build
    $ cmake ..
    $ make && make install
    $ export LD_INCLUDE_PATH={notepush_lib_dir}:$LD_INCLUDE_PATH
    $ export PATH={notepush_bin_dir}:$PATH
    

First Time Setup
---------------------
On first use, run as sudo so that notepush can write to "/etc/notepush/psh.config"

notepush will ask for the base directory of your git repository.

    $ sudo psh
    
License
=======

This library is distributed under the GNU general public license. For conditions of distribution and use,
see file `LICENSE.txt`.

Feedback
========

Any feedback is welcome.

[CMake]: https://cmake.org/
[GCC]: https://gcc.gnu.org/
[libgit2]: https://github.com/libgit2/libgit2
