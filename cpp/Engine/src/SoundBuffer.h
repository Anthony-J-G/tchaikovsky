#pragma once

// C Standard Library
#include <stdio.h>
#include <inttypes.h>
// C++ Standard Library
#include <iostream>
#include <vector>

// Sndfilelib
#include "sndfile.h"

// OpenAL
#include <AL/alc.h>
#include <AL/al.h>
#include <AL/alext.h>



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


// Singleton Class
class SoundBuffer {
public:
	static SoundBuffer* get();

	ALuint addSoundEffect(const char* filename);
	bool removeSoundEffect(const ALuint& buffer);

private:
	SoundBuffer();
	~SoundBuffer();

	std::vector<ALuint> p_SoundEffectBuffers;

};


class SoundSource {
public:
	SoundSource();
	~SoundSource();

	void Play(const ALuint play_buffer);

private:
	ALuint source;
	float pitch = 1.f;
	float gain = 0.125f;
	float position[3] = { 0, 0, 0 };
	float velocity[3] = { 0, 0, 0 };
	bool should_loop = false;
	ALuint buffer = 0;

};

