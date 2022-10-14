#pragma once
#include <AL/alc.h>

// Singleton Class
class SoundDevice {
public:
	SoundDevice(const SoundDevice&) = delete;

	static SoundDevice* get();

private:
	SoundDevice();
	~SoundDevice();

	ALCdevice* p_ALCDevice;
	ALCcontext* p_ALCContext;

};