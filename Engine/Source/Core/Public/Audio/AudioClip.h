#pragma once

#include <iostream>
#include <string>

#include <IrrKlang/irrKlang.h>

#include <FrostyCore.h>
#include <Audio/AudioSubsystem.h>

class FROSTY_CORE_API AudioClip
{
public:
	AudioClip(const std::string& filename);
	inline AudioClip(const std::string& filename, float volume) : AudioClip(filename) { this->SetVolume(volume); }
	~AudioClip();

	void Play(bool loop = false);
	void Stop();
	void Pause();
	void Resume();

	inline const float GetVolume () const { return this->m_Sound->getVolume(); }
	inline void SetVolume(float volume) { this->m_Sound->setVolume(static_cast<irrklang::ik_f32>(volume)); }

	inline const bool IsPlaying() const { return !(this->m_Sound->getIsPaused()); }
private:
	irrklang::ISound* m_Sound;
};