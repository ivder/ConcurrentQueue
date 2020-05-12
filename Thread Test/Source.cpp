#include "Queue.h"
#include <iostream>
#include <sstream>

const int limit = 12;

void print(std::string x) {
	static std::mutex mutex;
	std::unique_lock<std::mutex> locker(mutex);
	std::cout << x << "\n";
}


//void produce(Queue<int>& q) {
//	for (int i = 1; i <= 12; ++i) {
//		std::ostringstream tmp;
//		tmp << "--> " << i;
//		print(tmp.str());
//		q.push(i);
//	}
//}

void consume(Queue<int>& q) {
	for (int i = 0; i < limit; ++i) {
		auto item = q.pop();
		/*std::ostringstream tmp;
		tmp << "        " << item;
		print(tmp.str());*/
		std::cout << "---->" << item << std::endl;
	}
}

void test() {
	Queue<int> q;
	std::vector<std::thread> consumers;
	for (int i = 0; i < limit; ++i) {
		/*std::ostringstream tmp;
		tmp << "--> " << i;
		print(tmp.str());*/
		std::cout << i << std::endl;
		q.push(i);

		std::thread consumer(std::bind(&consume, std::ref(q)));
		consumers.push_back(std::move(consumer));
	}
	for (auto& consumer : consumers) {
		consumer.join();
	}
}

#include <thread>
int main()
{
	test();
	//Queue<int> q;
	//for (int i = 0; i < 12; ++i) {
	// Start the producer thread.
	//std::thread prod1(std::bind(produce, std::ref(q)));

	// Start the consumer threads.
	//std::vector<std::thread> consumers;
	//std::thread consumer(std::bind(&consume, std::ref(q)));

	//prod1.join();

	//consumer.join();
	//}

	system("pause");
}