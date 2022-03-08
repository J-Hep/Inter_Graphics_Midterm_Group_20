#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/RigidBody.h"

/// <summary>
/// A behavior that moves the character left and right
/// rigidbody of the parent when the space key is pressed
/// </summary>
class CharacterMovement : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<CharacterMovement> Sptr;

	std::weak_ptr<Gameplay::IComponent> Panel;

	CharacterMovement();
	virtual ~CharacterMovement();

	virtual void Awake() override;
	virtual void Update(float deltaTime) override;

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(CharacterMovement);
	virtual nlohmann::json ToJson() const override;
	static CharacterMovement::Sptr FromJson(const nlohmann::json& blob);

protected:
	float _impulse;
	glm::vec3 xPos;
	bool _isPressed = false;
	Gameplay::Physics::RigidBody::Sptr _body;
};