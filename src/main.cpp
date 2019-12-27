#include <notepush.h>
#include <main.h>
#include <string>
#include <git2.h>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <unordered_set>
#include <chrono>

struct Options
{
  std::string repo;
};

char* get_current_time()
{
  std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  return std::ctime(&time);
}

void write_note(const std::string& path, const std::string& note)
{  
     std::fstream outfile;
     outfile.open(path, std::ios::out | std::ios::app);

     outfile << get_current_time();// time has trailing '\n' built-in
     outfile << note << '\n\n'; 

     if (outfile.fail())
     {
       std::cerr << "Failure writing to file: " << path << ".\n";
       std::cerr << "This is usually caused by insufficient write permissions.\n"; 
     }

     outfile.close();

}

git_commit * getLastCommit ( git_repository * repo )
{
  int rc;
  git_commit * commit = NULL; /* the result */
  git_oid oid_parent_commit;  /* the SHA1 for last commit */

  /* resolve HEAD into a SHA1 */
  rc = git_reference_name_to_id( &oid_parent_commit, repo, "HEAD" );
  if ( rc == 0 )
  {
    /* get the actual commit structure */
    rc = git_commit_lookup( &commit, repo, &oid_parent_commit );
    if ( rc == 0 )
    {
      return commit;
    }
  }
  return NULL;
}

/// Option Handling

char *getCmdOption(char **begin, char **end, const std::string &option)
{
  char **itr = std::find(begin, end, option);
  if (itr != end && ++itr != end)
  {
    return *itr;
  }
  return 0;
}

bool cmdOptionExists(char **begin, char **end, const std::string &option)
{
  return std::find(begin, end, option) != end;
}

/// End Option Handling

int main(int argc, char *argv[])
{

  // notepush::test();
  // char *filename = getCmdOption(argv, argv + argc, "-f");

  if (cmdOptionExists(argv, argv + argc, "-h"))
  {
    std::cout<<HEADER<<USAGE<<"\n";
    return 0;
  }

    if (cmdOptionExists(argv, argv + argc, "-r"))
  {
    std::string answer;
    std::cout << "Are you sure you want to reset your configuration? Y or N\n";
    std::cin >> answer;

    if (answer == "Y")
    {
      std::filesystem::remove("/etc/notepush/psh.config");
    }

    return 0;
  }

  /*  On first boot, create a config file interactively with the user */
  if (!std::filesystem::is_directory("/etc/notepush"))
  {
    std::cerr << "Creating new config directory: /etc/notepush\n";
    std::filesystem::create_directory("/etc/notepush");
  }

  // if true, then config file needs to be created
  if (!std::filesystem::is_regular_file("/etc/notepush/psh.config"))
  {
    std::cerr << "Creating new config file: /etc/notepush/psh.config\n";

    std::string repo;
    std::cout << "Enter repo dir location: ";
    std::cin >> repo;
    std::cout << "\n";

    std::ofstream config("/etc/notepush/psh.config");

    config << repo << std::endl;

    config.close();
  }


  /// load the options/config
  Options options;
  std::ifstream config_file("/etc/notepush/psh.config");
  std::string line;
  while (std::getline(config_file, line))
  {
    options.repo = std::move(line);
  }


  //check to see if the user provided repo actually exists, if not, create it.
  /* Open repository in given directory (or fail if not a repository) */
  git_libgit2_init();

  int error;
  git_repository *repo = NULL;
  error = git_repository_open_ext(&repo, &options.repo[0], GIT_REPOSITORY_OPEN_NO_SEARCH, NULL);

  if (error)
  {
    std::cerr << "Repository: " << options.repo << " is not a valid git repo.\n";
    std::cerr << "Please create a valid repository in the provided repo path.\n";
    
    return 1;
  }

  /*

  // get the remotes
  git_strarray remotes = {0};
  error = git_remote_list(&remotes, repo);

  std::cout << remotes.strings[0] << std::endl;

  git_remote *remote;

  */

  /* lookup the remote */

  // error = git_remote_lookup(&remote, repo, "origin");
  // error = git_remote_fetch(remote,
  //                         NULL, /* refspecs, NULL to use the configured ones */
  //                         NULL, /* options, empty for defaults */
  //                         NULL); /* reflog mesage, usually "fetch" or "pull", you can leave it NULL for "fetch" */



  // git_commit *head = getLastCommit(repo);

  // const char *message = git_commit_message(head);

  // std::cout << message << "\n";


  
  

  /*
  The user provides a note with hashtags being used as the topical indicators. 

  The repo will contain the following files:

  general.txt - All of the notes with timestamps
  Topic1.txt - Any notes tagged with Topic1.
  Topic2.txt - Any notes tagged with Topic2.
  TopicN.txt - Any notes tagged with TopicN.
  */

  std::stringstream note;
  std::unordered_set<std::string> topics;

  for (int i = 1; i < argc; i++)
  {
    if (argv[i][0] == '@')
    {
      topics.emplace(std::string(argv[i]));
    } else
    {
      note << argv[i] << " ";
    }
  }

  /// all notes get written to general. 
  write_note(options.repo + "/general.txt", note.str());

  /// write notes to their respective files
  for (const auto& topic : topics)
  {
    write_note(options.repo + "/" + topic.substr(1) + ".txt", note.str());
  }

  return 0;
}
