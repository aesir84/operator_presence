#include "stdafx.h"

#include "OperatorModelBuilder.h"

#include "OperatorModel.h"

namespace operator_model
{
	Builder::Builder(std::shared_ptr<IMediator> mediator)
	{
		m_model = std::make_shared<OperatorModel>(mediator);
	}

	Builder::~Builder()
	{ }

	std::shared_ptr<IOperatorModel> Builder::build()
	{
		return m_model;
	}
}
