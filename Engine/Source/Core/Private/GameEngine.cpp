#include <GameEngine.h>
#include <FrostyGraphics.h>
#include <FrostyInput.h>

void GameEngine::Start()
{
	if (this->m_Running == true)
	{
		return;
	}

	this->m_Window = new Window("Frosty Engine", this->m_Width, this->m_Height);
	this->m_GameInstance = new GameInstance();
	this->m_GameInstance->Start();
	this->Run();
}

void GameEngine::Stop()
{
	if (this->m_Running == false)
	{
		return;
	}

	this->m_Running = false;
}
void GameEngine::Run()
{
	this->m_Running = true;

	double lastFrameTime = Time::GetTime();
	double frameTimer = 0;
	double updateTimer = 0;

	int frameCount = 0;
	int updateCount = 0;

	while (this->m_Running)
	{
		bool doRender = false;
		double currentFrameTime = Time::GetTime();
		double passedFrameTime = currentFrameTime - lastFrameTime;
		lastFrameTime = currentFrameTime;

		updateTimer += passedFrameTime;
		frameTimer += passedFrameTime;

		if (frameTimer >= 1.0)
		{
			this->m_UpdatesPerSecond = updateCount;
			this->m_FramesPerSecond = frameCount;

			std::cout << "FPS: " << this->GetFPS() << ", UPS: " << this->GetUPS() << "\n";

			frameCount = 0;
			updateCount = 0;
			frameTimer = 0;

			this->m_GameInstance->Tick();
		}

		while (updateTimer > this->m_FrameTime)
		{
			if (this->m_Window->IsCloseRequested())
			{
				this->Stop();
			}

			Time::SetDeltaTime(this->m_FrameTime);
			Input::Update();
			this->m_GameInstance->Update();

			doRender = true;
			updateTimer -= this->m_FrameTime;
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
}