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

		private:
			Window(std::shared_ptr<IMediator> mediator);

		private:
			std::shared_ptr<IMediator> m_mediator;

		private:
			virtual void initialize(std::uint16_t width, std::uint16_t height) override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			void render();
			void setOperatorDisplaySize(std::uint16_t width, std::uint16_t height);
		};
	}
}
