#include "ProjectileHandler.h"
#include "Gameplay/Components/CharacterMovement.h"
#include <GLFW/glfw3.h>
#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Utils/ImGuiHelper.h"
#include "Gameplay/InputEngine.h"

void ProjectileHandler::Awake()
{
	_body = GetComponent<Gameplay::Physics::RigidBody>();
	if (_body == nullptr) {
		IsEnabled = false;
	}

}

void ProjectileHandler::RenderImGui() {
	//LABEL_LEFT(ImGui::DragFloat, "Impulse", &_impulse, 1.0f);
}

nlohmann::json ProjectileHandler::ToJson() const {
	return {
		{ "impulse", _impulse }
	};
}

ProjectileHandler::ProjectileHandler() :
	IComponent()
	//_impulse(10.0f)
{ }

ProjectileHandler::~ProjectileHandler() = default;

ProjectileHandler::Sptr ProjectileHandler::FromJson(const nlohmann::json & blob) {
	ProjectileHandler::Sptr result = std::make_shared<ProjectileHandler>();
	result->_impulse = blob["impulse"];
	return result;
}

void ProjectileHandler::Update(float deltaTime) {

	//Needs a way to tell which direction to fire.
	GLfloat ProjectilePosY = GetGameObject()->GetPosition().y + 10 * deltaTime;

	if(isEnemy == false) {
		 ProjectilePosY = GetGameObject()->GetPosition().y - 10 * deltaTime;
	}
	
	GetGameObject()->SetPostion(glm::vec3(GetGameObject()->GetPosition().x, ProjectilePosY, GetGameObject()->GetPosition().z));

}