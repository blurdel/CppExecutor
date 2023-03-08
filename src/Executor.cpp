#include "Executor.h"
#include <iostream>

int Executor::mCnt = 0;

Executor::Executor(std::string pName) :
mName(pName),
mPool{ 1, /*std::thread::hardware_concurrency()*/ }
{
	std::cout << "Creating Executor " << mName << std::endl;
}

Executor::~Executor()
{
	mPool.join();
	std::cout << "~" << mName << std::endl;
}

void Executor::execute(const tJOBFUNC& pJob, int x)
{
	boost::asio::post(mPool, std::bind(pJob, x));
	std::cout << mName << " mCnt=" << mCnt << std::endl;
}
