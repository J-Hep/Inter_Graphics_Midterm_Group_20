#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/RigidBody.h"
class ProjectileHandler : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<ProjectileHandler> Sptr;

	std::weak_ptr<Gameplay::IComponent> Panel;

	ProjectileHandler();
	virtual ~ProjectileHandler();

	virtual void Awake() override;
	virtual void Update(float deltaTime) override;

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(ProjectileHandler);
	virtual nlohmann::json ToJson() const override;
	static ProjectileHandler::Sptr FromJson(const nlohmann::json& blob);

protected:
	float _impulse;
	glm::vec3 xPos;
	bool _isPressed = false;
	bool isEnemy = false;
	Gameplay::Physics::RigidBody::Sptr _body;
};