#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

#include <FrostyCore.h>
#include <FrostyGraphics.h>
#include <FrostyAudio.h>

// FIX ME
#include <Graphics/Shaders/BasicShader.h>
#include <Graphics/Material.h>

#include <System/File.h>
#include <Utilities/Random.h>

#include <FractalShader.h>

class Game : GameInstance
{
public:
	void Start() override
	{
		Vertex vertices[] =
		{
			Vertex(Vector3f(-1, -1, 0), Vector2f(0, 0)),
			Vertex(Vector3f(0, 1, 0), Vector2f(0.5f, 0)),
			Vertex(Vector3f(1, -1, 0), Vector2f(1.0f, 0)),
			Vertex(Vector3f(0, -1, 1), Vector2f(0, 0.5f))
		};

		int indices[] =
		{
			0, 1, 3,
			3, 1, 2,
			2, 1, 0,
			0, 2, 3
		};

		this->m_Mesh = new Mesh(vertices, 4, indices, 12);
		this->m_Transform = new Transform();

		m_Material = new Material(Colour(255, 0, 0));
		this->m_Shader = BasicShader::GetInstance();

		m_AudioClip = new AudioClip("Assets/Audio/Tetris_theme.ogg", 0.1f);
		m_AudioClip->Play(true);
	}

	float distance;

	// Called every game loop 'iteration'
	void Update() override
	{
		lerpIntensity += static_cast<float>(Time::GetDeltaTime());
		if (this->m_Material->DiffuseColour != this->m_DestinationColour)
		{
			if (lerpIntensity > 1.0f) lerpIntensity = 1.0f;
			this->m_Material->DiffuseColour = Colour::Lerp(this->m_LerpColour, this->m_DestinationColour, lerpIntensity);
		}
		else if (this->m_Material->DiffuseColour == this->m_DestinationColour)
		{
			lerpIntensity = 0;
			this->m_LerpColour = this->m_DestinationColour;
			this->m_DestinationColour = Random::RGB();
		}

		if (Input::GetKeyDown(Key::KEY_SPACE))
		{
			if (this->m_AudioClip->IsPlaying())
			{
				this->m_AudioClip->Pause();
			}
			else
			{
				this->m_AudioClip->Resume();
			}
		}

		if (Input::GetKey(Key::KEY_UP))
		{
			AudioSubsystem::SetGlobalVolume(AudioSubsystem::GetGlobalVolume() + 0.05f);
		}
		else if (Input::GetKey(Key::KEY_DOWN))
		{
			AudioSubsystem::SetGlobalVolume(AudioSubsystem::GetGlobalVolume() - 0.05f);
		}

		m_Transform->Update();
	}

	void Render() override
	{
		this->m_Shader->Start();
		this->m_Shader->Update(m_Transform->GetTransformation(), m_Transform->GetProjectedTransformation(), *m_Material);
		this->m_Mesh->Draw();
		this->m_Shader->Stop();
	}

	// Called every second
	void Tick() override
	{
		int ups = Application::GetEngine()->GetUPS();
		int fps = Application::GetEngine()->GetFPS();

		std::string title = "Frosty Engine | UPS: " + std::to_string(ups) + ", FPS: " + std::to_string(fps);
		Application::GetEngine()->GetWindow()->SetTitle(title.c_str());
	}

	void Shutdown() override
	{
		delete this->m_AudioClip;
		delete this->m_Mesh;
		delete this->m_Material;
		delete this->m_Transform;
	}
private:
	AudioClip* m_AudioClip;

	Mesh* m_Mesh;
	BasicShader* m_Shader;
	Transform* m_Transform;
	Material* m_Material;

	Colour m_LerpColour;
	Colour m_DestinationColour;

	float lerpIntensity;
};