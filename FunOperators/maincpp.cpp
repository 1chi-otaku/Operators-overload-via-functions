#include <iostream>
#include "Date.h"
#include "Functions.h"
using namespace std;
int main() {
	Date obj(15, 12, 2022);
	Date obj3(11, 10, 1000);
	Date obj2(5 - obj);
	obj2.Print();
	
	
	return 0;
}
	