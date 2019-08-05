///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#include "..\..\..\Engine\libraries\sdl2\include\SDL.h"

namespace engine
{
	class Sound
	{

	private:
		SDL_AudioDeviceID deviceId;
		SDL_AudioSpec wavSpec;
		Uint32 wavLength;
		Uint8 *wavBuffer;

	public:
		Sound()
		{
			SDL_InitSubSystem(SDL_INIT_AUDIO);
			SDL_AudioInit("directsound");

		}

		~Sound()
		{
		}

		void load(const char * filename, int frequency, SDL_AudioFormat format, int channels, Uint16 samples)
		{
			SDL_AudioSpec want, have;

			SDL_memset(&want, 0, sizeof(want));

			want.freq = frequency;
			want.format = format;
			want.channels = channels;
			want.samples = samples;
			want.callback = NULL;

			SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength);
			deviceId = SDL_OpenAudioDevice(SDL_GetAudioDeviceName(0, 0), 0, &want, &have, 0);

			const char* a = SDL_GetError();
			
			
			for (int i = 0; i < SDL_GetNumAudioDevices(0); ++i) {
				const char* o = SDL_GetAudioDeviceName(i, 0);
				int c = 0;
			}

		}

		void play()
		{
			int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
			SDL_PauseAudioDevice(deviceId, 0);
		}
	};

}