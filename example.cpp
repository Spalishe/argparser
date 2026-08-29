#include "argparser.cpp" // Include argparser

int main(int argc, char* argv[])
{
  arp::Argparser ap(argc, argv); // Initialize the main object
                                 // Set the program description
  ap.setDescription("Test program buru :3");
  // Add a required positional argument named argname0
  auto arg0 = ap.add<arp::sint>("argname0", "Argument 0", arp::required, arp::pos);
  // Add a required positional argument named argname1
  auto arg1 = ap.add<arp::str>("argname1", "Argument 1", arp::required, arp::pos);
  // Add a required non-positional argument named argname2
  auto arg2 = ap.add<arp::def>("--argname2", "Argument 2", arp::required, arp::nopos, "-an2");
  // Add a non-required non-positional argument named argname3
  auto arg3 = ap.add<arp::uint>("--argname3", "Argument 3", arp::norequired, arp::nopos, "-an3");
  // Add a vector of same arguments named argname4
  auto arg4 = ap.add_multiple<arp::str>("--argname4", "Argument 4", arp::norequired, "-an4");
  ap.parse();

  std::cout << arg0->val() << std::endl;
  std::cout << arg1->val() << std::endl;
  // These two lines are the same because type is arp::def
  std::cout << arg2->val() << std::endl;
  std::cout << arg2->defined() << std::endl;
  // arg3 will differ from arg1 because arg3 is unsigned
  std::cout << arg3->val() << std::endl;
  // Print out all positional arguments that were given to the program
  std::cout << "All positionals:" << std::endl;
  for(auto& c : ap.getPositionalArgs())
  {
    std::cout << c << std::endl;
  }
  // Print out all strings that was defined under arg4
  std::cout << "All strings in arg4:" << std::endl;
  for(auto& c : *arg4)
  {
    std::cout << c.val() << std::endl;
  }
  return 0;
}
