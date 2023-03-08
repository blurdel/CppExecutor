#include <iostream>
#include "ExecutorManager.h"


int main()
{
	std::cout << "boost169" << std::endl;

	auto fx = [](int x) {
		for (int i = 0; i < x; ++i) {
			std::cout << "##### " << i << std::endl;
			std::flush(std::cout);
		}
	};

	auto& exe1 = ExecutorManager().instance().createExecutor("myExe1");
	exe1.execute(fx, 3);

	auto& exe2 = ExecutorManager().instance().createExecutor("Exe #2");
	exe2.execute(fx, 5);


	std::cout << "Main Done." << std::endl;
	return 0;
}
