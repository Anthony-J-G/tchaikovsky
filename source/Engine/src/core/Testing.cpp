#include "../Testing.h"

#include <iostream>
#include <fstream>

#include <Eigen/Dense>
#include <AL/al.h>
#include <sndfile.h>
#include <json/json.h>

#include "../SoundDevice.h"
#include "../SoundSource.h"
#include "../SoundBuffer.h"
#include "../Oscillator.h"



namespace tests {

	void CheckExternal() {
		std::cout << "Testing Connection to External Dependencies:" << std::endl;

		// Eigen
		Eigen::Matrix2d M; // Dynamic - resizable matrix
		M.size();
		std::cout << "\t- Eigen\t\t...OK" << std::endl;
		
		// OpenAL
		std::cout << "\t- OpenAL\t...OK" << std::endl;

		// Libsndfile
		std::cout << "\t- Libsndfile\t...OK" << std::endl;

		// Jsoncpp
		Json::Reader reader;
		Json::Value root;

		std::string text = "{ \"first\": 1, \"second\": 2}";

		if (!reader.parse(text, root)) {
			std::cout << reader.getFormattedErrorMessages() << std::endl;
		}

		std::cout << "\t- Jsoncpp\t...OK" << std::endl;
	}


	void CheckPlayback() {
		std::cout << "Starting Playback...\n";

		tests::CheckExternal();

		SoundDevice* main_snd_dev = SoundDevice::get();
		ALCuint sound1 = SoundBuffer::get()->addSoundEffect("C:\\Dev\\art\\tchaikovsky\\audio\\gerudo_valley.wav");

		SoundSource speaker;

		speaker.Play(sound1);

	}

}