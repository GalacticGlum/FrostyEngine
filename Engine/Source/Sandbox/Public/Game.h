#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <functional>

#include <FrostyCore.h>
#include <FrostyGraphics.h>
#include <FrostyAudio.h>

// FIX ME
#include <Graphics/Shaders/BasicShader.h>
#include <Graphics/Shaders/PhongShader.h>
#include <Graphics/Material.h>

#include <System/File.h>
#include <Utilities/Random.h>
#include <System/Delegate.h>

class Game : GameInstance
{
public:
	void Start() override
	{
		//Vertex vertices[] = 
		//{ 
		//	Vertex(Vector3f(-1.0f, -1.0f, 0.5773f), Vector2f(0.0f, 0.0f)),
		//	Vertex(Vector3f(0.0f, -1.0f, -1.15475f), Vector2f(0.5f, 0.0f)),
		//	Vertex(Vector3f(1.0f, -1.0f, 0.5773f), Vector2f(1.0f, 0.0f)),
		//	Vertex(Vector3f(0.0f, 1.0f, 0.0f), Vector2f(0.5f, 1.0f))
		//};

		//int indices[] = 
		//{
		//	0, 3, 1,
		//	1, 3, 2,
		//	2, 3, 0,
		//	1, 2, 0 
		//};

		float fieldDepth = 10.0f;
		float fieldWidth = 10.0f;

		Vertex vertices[] =
		{ 
			Vertex(Vector3f(-fieldWidth, 0.0f, -fieldDepth), Vector2f(0.0f, 0.0f)),
			Vertex(Vector3f(-fieldWidth, 0.0f, fieldDepth * 3), Vector2f(0.0f, 1.0f)),
			Vertex(Vector3f(fieldWidth * 3, 0.0f, -fieldDepth), Vector2f(1.0f, 0.0f)),
			Vertex(Vector3f(fieldWidth * 3, 0.0f, fieldDepth * 3),Vector2f(1.0f, 1.0f))
		};

		int indices[] = 
		{ 
			0, 1, 2,
			2, 1, 3 
		};

		this->m_Mesh = new Mesh(vertices, 4, indices, 6, true);
		this->m_Transform = new Transform();
		this->m_Camera = new Camera();

		this->m_Material = new Material("Assets/Textures/Brick.jpg");
		this->m_Material->SpecularIntensity = 0.1f;
		this->m_Shader = PhongShader::GetInstance();
		
		this->m_Shader->SetAmbientColour(Colour(25.5f, 25.5f, 25.5f));
		this->m_Shader->SetDirectionalLight(DirectionalLight(Light(Colour::White, 0.1f), Vector3f(1, 1, 1)));

		this->m_PointLight = new PointLight(Light(Colour(0, 255.5f, 0), 0.4f), AttenuationCurve(0, 0, 1), Vector3f(-2, 0, 5), 10);
		this->m_Shader->SetPointLights(this->m_PointLight, 1);

		m_AudioClip = new AudioClip("Assets/Audio/Tetris_theme.ogg", 0.05f);
	}

	// Called every game loop 'iteration'
	void Update(float deltaTime) override
	{
		lerpIntensity += static_cast<float>(deltaTime);

		this->m_Transform->SetPosition(0, -1, 5);
		this->m_PointLight->Position = (Vector3f(3, 0, 8.0f * (float)(std::sin(lerpIntensity) + 1.0 / 2.0) + 10));

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

		this->m_Camera->Update(deltaTime);
	}

	void Render() override
	{
		this->m_Shader->Start();
		this->m_Shader->Update(m_Transform->GetTransformation(), *m_Camera, *m_Material);
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
		delete this->m_Camera;
	}
private:
	AudioClip* m_AudioClip;

	Mesh* m_Mesh;
	PhongShader* m_Shader;
	Transform* m_Transform;
	Camera* m_Camera;
	Material* m_Material;
	PointLight* m_PointLight;

	Colour m_LerpColour;
	Colour m_DestinationColour;

	float lerpIntensity;
};