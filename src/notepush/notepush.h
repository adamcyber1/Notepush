#ifndef CMAKE_NOTEPUSH_H
#define CMAKE_NOTEPUSH_H

#include <iostream>
#include <git2.h>

namespace notepush {


void test() {

  std::cout<<"I must be working3...or something. \n";

  git_libgit2_init();

    // Open a repository
  git_repository *repo;
  int error = git_repository_open(&repo, "/home/alfilli/scratch/test");

  // Dereference HEAD to a commit
  git_object *head_commit;
  error = git_revparse_single(&head_commit, repo, "HEAD^{commit}");
  git_commit *commit = (git_commit*)head_commit;

  // Print some of the commit's properties
  printf("%s", git_commit_message(commit));
  const git_signature *author = git_commit_author(commit);
  printf("%s <%s>\n", author->name, author->email);
  const git_oid *tree_id = git_commit_tree_id(commit);

  // Cleanup
  git_commit_free(commit);
  git_repository_free(repo);
  

}


}


#endif //CMAKE_NOTEPUSH_H
