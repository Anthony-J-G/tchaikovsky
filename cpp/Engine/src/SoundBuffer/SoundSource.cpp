#include "../SoundBuffer.h"



SoundSource::SoundSource()
{
	alGenSources(1, &source);
	alSourcef(source, AL_PITCH, pitch);
	alSourcef(source, AL_GAIN, gain);
	alSource3f(source, AL_POSITION, position[0], position[1], position[2]);
	alSource3f(source, AL_VELOCITY, velocity[0], velocity[1], velocity[2]);
	alSourcei(source, AL_LOOPING, should_loop);
	alSourcei(source, AL_BUFFER, buffer);

}

SoundSource::~SoundSource()
{
	alDeleteSources(1, &source);
}


void SoundSource::Play(const ALuint play_buffer) {
	if (play_buffer != buffer) {
		buffer = play_buffer;
		alSourcei(source, AL_BUFFER, (ALint)buffer);
	}

	alSourcePlay(source);

	ALint state = AL_PLAYING;
	std::cout << "playing sound...\n";
	while (state == AL_PLAYING && alGetError() == AL_NO_ERROR) {
		alGetSourcei(source, AL_SOURCE_STATE, &state);
	}
	std::cout << "done playing sound\n";

}