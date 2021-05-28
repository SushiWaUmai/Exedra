#pragma once
#include <GLFW/glfw3.h>
#include "src/events/event.h"
#include "src/events/eventdispatcher.h"
#include "src/resources/model.h"
#include "src/graphics/camera.h"
#include "src/ecs/drawer.h"
#include <vector>
#include <memory>

namespace exedra {
	namespace graphics {
		class Renderer {
		public:
			Renderer() = default;
			~Renderer();
			void Init(GLFWwindow* _window);

			static void Clear();
			void Draw();
			void SetClearColor(float _r, float _g, float _b, float _a);
			void SetClearColor(glm::vec4 _rgba);
			void AddDrawer(const std::shared_ptr<ecs::Drawer>& _model);
		private:
			Camera cam;
			std::vector<std::shared_ptr<ecs::Drawer>> models;
		};
	}
}