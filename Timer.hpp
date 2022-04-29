//timer class with chrono
#include <chrono>

using namespace std; 

class Timer {
    private:
	    using clock_type = chrono::steady_clock;
	    using second_type = chrono::duration<double, ratio<1> >;

	    chrono::time_point<clock_type> m_beg { clock_type::now() };

    public:
	    void reset() {
		    m_beg = clock_type::now();
	    }

	double elapsed() const {
		return chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
	}
};