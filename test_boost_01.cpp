#include "boost/algorithm/string.hpp"
#include "string"
#include "vector"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> svec{"Hello","World"};
    cout<<boost::algorithm::join(svec," - ")<<endl;

    return 0;
}
