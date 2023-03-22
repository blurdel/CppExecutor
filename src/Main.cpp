#include <iostream>
#include "ExecutorManager.h"


int main()
{
	std::cout << "boost test" << std::endl;

	auto fx = [](int x) {
		for (int i = 0; i < x; ++i) {
			std::cout << "##### " << i << std::endl;
			std::flush(std::cout);
		}
	};

	auto& exe1 = ExecutorManager::instance().createExecutor("Exe #1");
	exe1.execute(fx, 2);

	auto& exe2 = ExecutorManager::instance().createExecutor("Exe #2");
	exe2.execute(fx, 4);


	std::cout << "Main Done." << std::endl;
	return 0;
}
