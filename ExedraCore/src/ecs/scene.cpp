#include "scene.h"
#include "drawer.h"
#include "camera.h"
#include "cameramovement.h"

namespace exedra {
	namespace ecs {
		Scene* Scene::current;

		Scene::Scene() {
			current = this;

			std::unique_ptr<ComponentSystem> cameraSystem = std::make_unique<CameraSystem>();
			componentSystems.push_back(std::move(cameraSystem));

			std::unique_ptr<CameraMovementSystem> cameraMovementSystem = std::make_unique<CameraMovementSystem>();
			componentSystems.push_back(std::move(cameraMovementSystem));
		}

		void Scene::Init() {
			Entity e = AddEntity();
			e.AddComponent<CameraMovementComponent>();
			TransformComponent& transform = e.AddComponent<TransformComponent>();
			//transform.position = { 0, 1, -10 };
			e.AddComponent<CameraComponent>(60, 0.1, 100);
		}

		Entity Scene::AddEntity() {
			return entityRegistry.create();
		}

		void Scene::RemoveEntity(Entity _id) {
			entityRegistry.destroy(_id);
		}

		bool Scene::EntityIsValid(entt::entity _id) const {
			return entityRegistry.valid(_id);
		}

		void Scene::Update() {
			for (uint32_t i = 0; i < componentSystems.size(); i++) {
				componentSystems[i]->Update(entityRegistry);
			}
		}
	}
}