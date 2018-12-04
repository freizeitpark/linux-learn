#include <boost/utility.hpp>
#include <iostream>
using namespace std;
class myclass : public boost::noncopyable {
public:
    myclass() {}
    myclass(int i) {}
};


#define BOOST_LOG_DYN_LINK

#include <boost/log/trivial.hpp>

int main_log()
{
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    return 0;
}




int main() {
    cout << " boost test begin " << endl;
    myclass c1();
    myclass c2(1);
    // myclass c3(c1);
    // myclass c3 = c1;

    cout << " boost test end " << endl;
      
   main_log();

    return 0;
 }
