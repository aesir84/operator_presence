#pragma once

#include "IOperatorView.h"

namespace operator_view
{
	class IDevice;
}

namespace operator_view
{
	class OperatorView : public IOperatorView
	{
		friend class Builder;

	private:
		OperatorView(std::shared_ptr<IDevice> device);

	private:
		std::shared_ptr<IDevice> m_device;

	private:
		virtual void initialize() override;
		virtual void render() override;
	};
}
