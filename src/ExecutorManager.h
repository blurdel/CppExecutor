#ifndef EXECUTORMANAGER_H_
#define EXECUTORMANAGER_H_

#include <string>
#include <vector>
#include "Executor.h"


class ExecutorManager {
public:
	~ExecutorManager();

	static ExecutorManager& instance() {
		static ExecutorManager instance;
		return instance;
	}

	Executor& createExecutor(std::string id);

private:
	ExecutorManager();
	std::vector<Executor*> mPool;

};

#endif
