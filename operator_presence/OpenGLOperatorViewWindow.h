#pragma once

#include "IOperatorViewWindow.h"

namespace operator_view
{
	class IMediator;
}

namespace operator_view
{
	namespace opengl
	{
		class Window : public IWindow
		{
			friend class Factory;

		public:
			~Window();

		private:
			Window(std::shared_ptr<IMediator> mediator);

		private:
			std::shared_ptr<IMediator> m_mediator;

		private:
			virtual void initialize(std::uint16_t & width, std::uint16_t & height) override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			sf::Window m_window;

		private:
			void render();
			void adaptWindowSizeToScreenSize(std::uint16_t & width, std::uint16_t & height);
		};
	}
}
