#pragma once

#include "IOperatorRendererDecorator.h"
#include "IOperatorView.h"

namespace operator_view
{
	class IOperatorViewObserver;
}

namespace operator_view
{
	class IOperatorOculusRiftRenderer : public IOperatorRendererDecorator, public IOperatorView
	{
	public:
		IOperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate)
			: IOperatorRendererDecorator(operatorRendererToDecorate)
		{ }

	public:
		virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) = 0;

	public:
		virtual void notifyOrientationChanged(double yaw, double pitch, double roll) = 0;
		virtual void notifyErrorOccured(std::string const & errorDescription) = 0;
	};
}
