#include "../SoundBuffer.h"



SoundDevice* SoundDevice::get() {
	static SoundDevice* snd_device = new SoundDevice();
	return snd_device;
};

SoundDevice::SoundDevice() {
	p_ALCDevice = alcOpenDevice(nullptr); //  nullptr parameter indicates that we want to get the default device (can pass string argument instead)
	if (!p_ALCDevice) { throw("failed to find default sound device"); }

	p_ALCContext = alcCreateContext(p_ALCDevice, nullptr); // set context
	if (!p_ALCContext) { throw("failed to initialize sound context"); }

	// Set Current Context
	if (!alcMakeContextCurrent(p_ALCContext)) { throw("failed to make context current"); }

	const ALCchar* name = nullptr;
	if (alcIsExtensionPresent(p_ALCDevice, "ALC_ENUMERATE_ALL_EXT")) {
		name = alcGetString(p_ALCDevice, ALC_ALL_DEVICES_SPECIFIER);
	}
	if (!name || alcGetError(p_ALCDevice) != AL_NO_ERROR) {
		name = alcGetString(p_ALCDevice, ALC_DEVICE_SPECIFIER);
	}

	printf("Opened \"%s\"\n", name);

}

SoundDevice::~SoundDevice() {
	if (!alcMakeContextCurrent(nullptr)) { throw("failed to set context to nullptr"); }

	alcDestroyContext(p_ALCContext);
	if (p_ALCContext) { throw("failed to unset during close"); }

	if (!alcCloseDevice(p_ALCDevice)) { throw("failed to close sound device"); }
}