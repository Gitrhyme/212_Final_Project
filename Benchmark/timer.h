#ifndef TIMER_H
#define TIMER_H


#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
using namespace std::chrono;

class Timer {
	private:
		time_point<system_clock> start_point;
		time_point<system_clock> end_point;
		double duration;

	public:
		Timer();
		~Timer();
		void start();
		void stop();
		double getDuration();
};

inline void Timer::start() {
	start_point = system_clock::now();
}

inline void Timer::stop() {
	end_point = system_clock::now();
}

inline double Timer::getDuration() {
	duration = duration_cast<nanoseconds>(end_point - start_point).count();
	duration = duration / 1000;
	return duration;
}

#endif;