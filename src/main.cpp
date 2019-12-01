#include <notepush.h>
#include <main.h>
#include <algorithm>
#include <string>

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

int main(int argc, char *argv[])
{

  notepush::test();

  if (cmdOptionExists(argv, argv + argc, "-h") || cmdOptionExists(argv, argv + argc, "-h"))
  {
    std::cout<<HEADER<<USAGE<<"\n";
    return 0;
  }

  char *filename = getCmdOption(argv, argv + argc, "-f");

  if (filename)
  {
    return 0;
  }

  return 0;
}
