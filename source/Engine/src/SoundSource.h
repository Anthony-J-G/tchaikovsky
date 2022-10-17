#pragma once

#include <AL/al.h>


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

