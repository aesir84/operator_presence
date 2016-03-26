#include "stdafx.h"

#include "OperatorViewBuilder.h"

#include "IOperatorModel.h"

#include "IOperatorViewFactory.h"
#include "IOperatorViewRift.h"
#include "IOperatorViewVision.h"
#include "IOperatorViewWindow.h"

#include "OperatorView.h"

namespace operator_view
{
	Builder::Builder(std::shared_ptr<operator_model::IOperatorModel> model, std::shared_ptr<IMediator> mediator, std::unique_ptr<IFactory> factory)
		: m_model(model)
		, m_mediator(mediator)
		, m_factory(std::move(factory))
	{
		//
		// Compose what is a must for the view.
		//

		auto window = m_factory->createWindow(m_mediator);
		auto vision = m_factory->createVision(window);
		
		m_model->registerObserver(vision);

		m_renderer = vision;
	}

	Builder::~Builder() = default;

	std::shared_ptr<IOperatorView> Builder::build(DeviceType deviceType)
	{
		//
		// Take what has been built so far and apply the requested strategy.
		//

		std::shared_ptr<IDevice> device;

		switch (deviceType)
		{
			case DeviceType::Rift:
			{
				device = m_factory->createRift(m_renderer, m_mediator);
			}
			break;

			default:
			{
				assert(false);
			}
		}

		// Return the view parametrized with the requested device type.
		//
		return std::shared_ptr<IOperatorView>(new OperatorView(device));
	}
}
