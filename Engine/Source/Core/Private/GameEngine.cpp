#include <GameEngine.h>
#include <Graphics/Window.h>

void GameEngine::Start()
{
	if (this->m_Running)
	{
		return;
	}

	this->m_Window = new Window("Frosty Engine", 800, 600);
	this->m_GameInstance->Initialize();
	this->Run();
}

void GameEngine::Run()
{
	this->m_Running = true;

	double previousFrameTime = Time::GetTime();
	double frameTimer = 0;
	double updateTimer = 0;

	int frameCount = 0;
	int updateCount = 0;

	while (this->m_Running)
	{
		bool doRender = false;
		double currentFrameTime = Time::GetTime();
		double passTime = currentFrameTime - previousFrameTime;
		previousFrameTime = currentFrameTime;

		updateTimer += passTime;
		frameTimer += passTime;

		this->m_DeltaTime = this->m_FrameTime;

		if (frameTimer >= 1.0)
		{
			this->m_UpdatesPerSecond = updateCount;
			this->m_FramesPerSecond = frameCount;

			frameCount = 0;
			updateCount = 0;
			frameTimer = 0;

			this->m_GameInstance->Tick();
		}

		while (updateTimer > this->m_FrameTime)
		{
			if (this->m_Window->IsClosed())
			{
				this->Stop();
			}

			this->m_GameInstance->Update();

			updateTimer -= this->m_FrameTime;
			doRender = true;
			updateCount++;
		}

		if (doRender)
		{
			this->Render();
			frameCount++;
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
	this->Shutdown();
}

void GameEngine::Render()
{
	this->m_Window->Clear();
	this->m_GameInstance->Render();
	this->m_Window->Update();
}

void GameEngine::Shutdown()
{
	this->m_GameInstance->Shutdown();
	delete this->m_Window;
	delete this->m_GameInstance;
	delete this;
}