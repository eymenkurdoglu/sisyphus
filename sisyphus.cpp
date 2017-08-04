#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <set>

using namespace std;

class B {
	protected:
		virtual void f() { cout << "B" << endl; }
	public:
		void g() { f(); }
};

class D : public B {
	protected:
		void f() { cout << "D" << endl; }
};

int main (int argc, char* argv[] ) {
//clock_t begin = clock();
//clock_t end = clock();
B* ptr = new D;
ptr->g();

return 0;
}
