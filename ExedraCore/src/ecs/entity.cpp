#include "entity.h"
#include "src/logging/log.h"

namespace exedra {
	namespace ecs {
		Entity::Entity(entt::entity _id) {
			entityID = _id;
		}

		Entity::operator entt::entity () {
			return entityID;
		}
	}
}