#include <iostream>
#include <sstream>
#include <string>

#include <FrostyCore.h>
#include <cmath>

#include <Graphics/Window.h>
#include <Graphics/Mesh.h>
#include <Graphics/Shader.h>
#include <Graphics/Transform.h>
#include <System/File.h>

class Game : GameInstance
{
public:
	void Initialize() override
	{
		Vertex vertices[] = 
		{
			Vertex(Vector3f(-1, -1, 0)),   
			Vertex(Vector3f(0, 1, 0)),  
			Vertex(Vector3f(1, -1, 0)),
			Vertex(Vector3f(0, -1, 1))
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
		this->m_Camera = new Camera();

		this->m_Shader = new Shader("Assets/Shaders/vertex.shader", "Assets/Shaders/fragment.shader");
		this->m_Shader->AddUniform("mvpMatrix");
	}

	// Called every game loop 'iteration'5
	void Update() override 
	{
		m_Time += (float)Application::GetGameEngineInstance()->GetDeltaTime();
		this->m_Camera->SetPosition(Vector3f(0, 0, std::sin(m_Time)));
		//this->m_Transform->SetPosition(0, 0, -5);
		this->m_Transform->Rotate(0, 0.01f, 0);
		//this->m_Transform->SetScale(Vector3f(std::sin(m_Time)));
	}

	void Render() override 
	{
		this->m_Shader->Start();

		this->m_Shader->SetUniform("mvpMatrix", this->m_Transform->GetProjectionMatrix());
		this->m_Mesh->Draw();

		this->m_Shader->Stop();
	}

	// Called every second
	void Tick() override
	{
		int ups = Application::GetGameEngineInstance()->GetUPS();
		int fps = Application::GetGameEngineInstance()->GetFPS();

		std::string title = "Frosty Engine | UPS: " + std::to_string(ups) + ", FPS: " + std::to_string(fps);
		Application::GetGameEngineInstance()->GetWindow()->SetTitle(title.c_str());
	}

	void Shutdown() override 
	{
		delete this->m_Mesh;
		delete this->m_Shader;
		delete this->m_Transform;
	}
private:
	Mesh* m_Mesh;
	Shader* m_Shader;
	Transform* m_Transform;
	Camera* m_Camera;

	float m_Time;
};