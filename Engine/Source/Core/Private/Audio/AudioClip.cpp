#include <Audio/AudioClip.h>
#include <Audio/AudioSubsystem.h>

AudioClip::AudioClip(const std::string& filename)
{
	this->m_Sound = AudioSubsystem::Load(filename);
}

AudioClip::~AudioClip()
{
	this->m_Sound->drop();
}

void AudioClip::Play(bool loop /* = true*/)
{
	this->m_Sound->setIsLooped(loop);
	this->m_Sound->setIsPaused(false);
}

void AudioClip::Stop()
{
	this->m_Sound->stop();
}

void AudioClip::Pause()
{
	this->m_Sound->setIsPaused(true);
}

void AudioClip::Resume()
{
	this->m_Sound->setIsPaused(false);
}