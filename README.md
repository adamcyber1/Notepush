Notepush
====================================

Command line tool that pushes notes to git.

**ATTENTION, this software is in the alpha state!**

Any [feedback][mail] (*especially results of testing*) is highly appreciated!

Features
========


Examples
=======

```console
foo@bar:~$ psh A profound hockey related thought #hockey
Notepush: Pushing note to {gitrepo}.

```

Installation 
==========================

Dependencies
------------

- [CMake] build system version 3.13+;
- C++17 compiler ([GCC] 7.3+)

Build time settings
-------------------

n/a

Installation on Linux
---------------------

    $ git clone https://github.com/adamfill28/Notepush
    $ mkdir build && cd build
    $ cmake ..
    $ make && make install


Tests 
==========================

There are no tests yet.

License
=======

This library is distributed under the XYZ license. For conditions of distribution and use,
see file `LICENSE.txt`.

Feedback
========

Any feedback are welcome. [Contact us][mail].

Copyright
=========

copyright info....

[mail]: mailto:fake@gmail.com

[CMake]: https://cmake.org/
[GCC]: https://gcc.gnu.org/