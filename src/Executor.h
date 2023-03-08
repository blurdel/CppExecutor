#ifndef EXECUTOR_H_
#define EXECUTOR_H_

#include <functional>
#include <string>
#include <thread>
#include <boost/asio.hpp>


typedef std::function<void(int)> tJOBFUNC;


class Executor {
public:
	Executor(std::string pName);
	virtual ~Executor();

	std::string getName() { return mName; }

	void execute(const tJOBFUNC& pJob, int x);

private:
	std::string mName;
	boost::asio::thread_pool mPool{};
	static int mCnt;
};

#endif
