#ifndef CMAKE_NOTEPUSH_H
#define CMAKE_NOTEPUSH_H

#include <iostream>
#include <git2.h>

namespace notepush {

void test() {

  std::cout<<"I must be working...or something. \n";

  git_libgit2_init();

  git_repository *repo;

}


}


#endif //CMAKE_NOTEPUSH_H
