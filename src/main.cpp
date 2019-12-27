#include <notepush.h>
#include <main.h>
#include <string>
#include <git2.h>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <fstream>

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

  if (cmdOptionExists(argv, argv + argc, "-h"))
  {
    std::cout<<HEADER<<USAGE<<"\n";
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

    return 0;
  }


  /*
  The user provides a note with hashtags being used as the topical indicators. 

  The repo will contain the following files:

  General.txt - All of the notes with timestamps
  Topic1.txt - Any notes tagged with Topic1.
  Topic2.txt - Any notes tagged with Topic2.
  TopicN.txt - Any notes tagged with TopicN.

  */

  char *filename = getCmdOption(argv, argv + argc, "-f");

  /*  Regular Operation */
  std::cout<<"Made it to regular operation wee \n";



  return 0;
}
