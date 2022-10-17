#include <iostream>
#include <fstream>

#include "Testing.h"
#include "Oscillator.h"


int BROKEN_FUNCTION_PLS_FIX_ME() {

	/*

	const char* infilename = "../../piano.json";

	std::cout << "Loading notes from: \"" << infilename << "\"" << std::endl;

	Instrument piano;
	int succeeded = piano.LoadNoteMap(infilename);

	std::cout << "\nDid Note Map Loading Succeed? " << succeeded << std::endl;
	std::cout << "Found Note Map of size: " << piano.GetNoteMapSize() << std::endl;

	std::vector<int> wf;

	std::vector<std::string> Members = piano.GetNoteNames();
	for (int i = 0; i < Members.size(); i++) {
		const char* name = Members[i].c_str();
		std::vector<int> stream = piano.RenderNote(name, 0.25);

		for (int j = 0; j < stream.size(); j++) {
			int packet = stream[j];
			wf.push_back(packet);
		}
		break;
		
	}


	const char* outfilename = "../../audio/waveform";

	std::ofstream file;
	file.open(outfilename, std::ios::binary);

	for (int i = 0; i < wf.size(); i++) {
		int packet = wf[i];
		file.write(reinterpret_cast<char*> (&packet), 2);
	}

	file.close();

	*/
	
	return 0;

	

}