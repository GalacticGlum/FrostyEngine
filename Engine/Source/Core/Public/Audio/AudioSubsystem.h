#pragma once

#include <iostream>

#include <string>
#include <map>

#include <IrrKlang/irrKlang.h>
#include <FrostyCore.h>

class FROSTY_CORE_API AudioSubsystem
{
public:
	static void Initialize();
	static void Update();
	static void Shutdown();

	inline static const float GetGlobalVolume() { return m_SoundEngine->getSoundVolume(); }
	inline static void SetGlobalVolume(float volume) { m_SoundEngine->setSoundVolume(volume); }

	static irrklang::ISound* Load(const std::string& filePath);
	inline static const irrklang::ISoundEngine* GetSoundEngine() { return m_SoundEngine; }
private:
	static irrklang::ISoundEngine* m_SoundEngine;
private:
};