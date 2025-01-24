#ifndef _ASYNCTIMER_h
#define _ASYNCTIMER_h

#include <Arduino.h>

typedef void(*AsyncTimerCallback)();

class AsyncTimer {
 public:
	AsyncTimer(unsigned long millisInterval);
	AsyncTimer(unsigned long millisInterval, AsyncTimerCallback OnFinish);

	void Start();
	void Reset();
	void Stop();
	bool Update();

	void SetIntervalMillis(unsigned long interval);
	
	unsigned long GetStartTime();
	unsigned long GetElapsedTime();
	unsigned long GetRemainingTime();

	bool IsActive() const;
	bool IsExpired() const;
	
	unsigned long Interval;
	
	AsyncTimerCallback OnFinish;

private:
	bool _isActive;
	bool _isExpired;
	unsigned long _startTime;
};
#endif