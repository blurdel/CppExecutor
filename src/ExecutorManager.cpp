#include "ExecutorManager.h"

#include <iostream>

ExecutorManager::ExecutorManager()
{
}

ExecutorManager::~ExecutorManager()
{
	for (auto exe : mPool) {
		delete exe;
		exe = nullptr;
	}
	mPool.clear();
	std::cout << "~ExecutorManager" << std::endl;
}

Executor& ExecutorManager::createExecutor(std::string id)
{
	Executor* exe = new Executor(id);
	mPool.push_back(exe);
	return *exe;
}
