/*
 * This file is part of Notepush.
 * 
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "notepush.h"

#include <chrono>
#include <fstream>

namespace notepush
{
void write_note(const std::string &path, const std::string &note)
{
  std::fstream outfile;
  outfile.open(path, std::ios::out | std::ios::app);

  outfile << get_current_time(); // time has trailing '\n' built-in
  outfile << note << "\n\n";

  if (outfile.fail())
  {
    std::cerr << "Failure writing to file: " << path << ".\n";
    std::cerr << "This is usually caused by insufficient write permissions.\n";
  }

  outfile.close();
}

char *get_current_time()
{
  std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  return std::ctime(&time);
}

git_commit *get_last_commit(git_repository *repo)
{
  int rc;
  git_commit *commit = NULL; /* the result */
  git_oid oid_parent_commit; /* the SHA1 for last commit */

  /* resolve HEAD into a SHA1 */
  rc = git_reference_name_to_id(&oid_parent_commit, repo, "HEAD");
  if (rc == 0)
  {
    /* get the actual commit structure */
    rc = git_commit_lookup(&commit, repo, &oid_parent_commit);
    if (rc == 0)
    {
      return commit;
    }
  }
  return NULL;
}
    
} // namespace name
