#include "absl/strings/str_join.h"
#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main() {
  vector<string> v = {"foo","bar","baz"};
  string s = absl::StrJoin(v, "-");

  cout << "Joined string: " << s << "\n";
}