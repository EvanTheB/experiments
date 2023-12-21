#include <iostream>
#include <ostream>
#include <string>

// Can you auto convert from c string to std::string ref?
// Does it auto allocate or just magic cast or what?

static int function(const std::string &s) {
	std::cout << s << std::endl;
    return 0;
}

int main() {
    std::string x = "abc";
    function(x);
    function(x.c_str());
    return 0;
}
