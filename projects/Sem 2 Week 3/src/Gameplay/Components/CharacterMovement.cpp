#include "Gameplay/Components/CharacterMovement.h"
#include <GLFW/glfw3.h>
#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Utils/ImGuiHelper.h"
#include "Gameplay/InputEngine.h"

void CharacterMovement::Awake()
{
	_body = GetComponent<Gameplay::Physics::RigidBody>();
	if (_body == nullptr) {
		IsEnabled = false;
	}

}

void CharacterMovement::RenderImGui() {
	//LABEL_LEFT(ImGui::DragFloat, "Impulse", &_impulse, 1.0f);
}

nlohmann::json CharacterMovement::ToJson() const {
	return {
		{ "impulse", _impulse }
	};
}

CharacterMovement::CharacterMovement() :
	IComponent()
	//_impulse(10.0f)
{ }

CharacterMovement::~CharacterMovement() = default;

CharacterMovement::Sptr CharacterMovement::FromJson(const nlohmann::json & blob) {
	CharacterMovement::Sptr result = std::make_shared<CharacterMovement>();
	result->_impulse = blob["impulse"];
	return result;
}

void CharacterMovement::Update(float deltaTime) {
	GLfloat PlayerXPos = GetGameObject()->GetPosition().x;
	GLfloat xPosL = PlayerXPos + 10 * deltaTime;
	GLfloat xPosR = PlayerXPos - 10 * deltaTime;

	bool _A = InputEngine::IsKeyDown(GLFW_KEY_A);
	bool _D = InputEngine::IsKeyDown(GLFW_KEY_D);

	if (_A)
	{
		GetGameObject()->SetPostion(glm::vec3(xPosL, GetGameObject()->GetPosition().y, GetGameObject()->GetPosition().z));
	}
	if (_D)
	{
		GetGameObject()->SetPostion(glm::vec3(xPosR, GetGameObject()->GetPosition().y, GetGameObject()->GetPosition().z));
	}
	//GetGameObject()->SetRotation(glm::vec3(90.0f, 0.0f, 0.0f));
}