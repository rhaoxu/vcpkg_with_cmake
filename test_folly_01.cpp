#include "folly/String.h"
#include "fmt/format.h"
#include "iostream"
#include "vector"

using namespace std;

int main(int, char**) {
  string str("Hello World");
  vector<string> svec;
  folly::split(" ", str, svec);
  for (const auto& val : svec) {
    cout << val << endl;
  }

  cout<<fmt::format("Hello {}\n","Ryan");

}
