#include <Audio/AudioSubsystem.h>

irrklang::ISoundEngine* AudioSubsystem::m_SoundEngine = nullptr;

void AudioSubsystem::Initialize()
{
	m_SoundEngine = irrklang::createIrrKlangDevice();
	if (m_SoundEngine == nullptr)
	{
		std::cout << "AudioSubsystem::Initialize: Failed to create sound engine!\n";
		exit(1);
	}
}

void AudioSubsystem::Update()
{
	m_SoundEngine->update();
}

void AudioSubsystem::Shutdown()
{
	m_SoundEngine->drop();
}

irrklang::ISound* AudioSubsystem::Load(const std::string& filePath)
{
	return m_SoundEngine->play2D(filePath.c_str(), false, true);
}