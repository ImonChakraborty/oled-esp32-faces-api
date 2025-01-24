#include "AsyncTimer.h"

AsyncTimer::AsyncTimer(unsigned long millisInterval) : AsyncTimer(millisInterval, nullptr) {}

AsyncTimer::AsyncTimer(unsigned long millisInterval, AsyncTimerCallback onFinish) {
	Interval = millisInterval;
	OnFinish = onFinish;
}

void AsyncTimer::Start() {
	Reset();
	_isActive = true;
}

void AsyncTimer::Reset() {
	_startTime = millis();
}

void AsyncTimer::Stop() {
	_isActive = false;
}

bool AsyncTimer::Update() {
	if (_isActive == false) return false;

	_isExpired = false;
	if (static_cast<unsigned long>(millis() - _startTime) >= Interval) {
		_isExpired = true;
		if (OnFinish != nullptr) OnFinish();
		Reset();
	}
	return _isExpired;
}

void AsyncTimer::SetIntervalMillis(unsigned long interval) {
	Interval = interval;
}

unsigned long AsyncTimer::GetStartTime() {
	return _startTime;
}

unsigned long AsyncTimer::GetElapsedTime() {
	return millis() - _startTime;
}

unsigned long AsyncTimer::GetRemainingTime() {
	return Interval - millis() + _startTime;
}

bool AsyncTimer::IsActive() const {
	return _isActive;
}

bool AsyncTimer::IsExpired() const{
	return _isExpired;
}