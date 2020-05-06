
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

class World
{
public:
	void set(std::string msg) 
    {
        current_time();
        printf("C++ set begin\n");
        mMsg = msg; 
        printf("C++ set end\n");
    }
    void current_time()
    {
        time_t curr_time;
        curr_time = time(NULL);

        tm *tm_local = localtime(&curr_time);
        cout << "\nCurrent local time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << "\n";
    }
	std::string many(boost::python::list msgs) {
        current_time();
		long l = len(msgs);
        printf("C++ begin %d\n", l);
		std::stringstream ss;
		for (long i = 0; i < l; ++i) {
			if (i > 0) ss << ", ";
			std::string s = boost::python::extract<std::string>(msgs[i]);
			ss << s;
		}
		mMsg = ss.str();
        printf("C++ end mMsg=%s\n", mMsg.c_str());

        return mMsg;
	}
	std::string greet() 
    {
        return mMsg; 
    }
	std::string mMsg;
};

using namespace boost::python;

BOOST_PYTHON_MODULE(classes)
{
    class_<World>("World")
        .def("greet", &World::greet)
        .def("set", &World::set)
        .def("many", &World::many)
    ;
};
