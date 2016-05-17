#include "stdafx.h"

#include "OperatorController.h"

int main(int argc, char ** argv)
{
	QCoreApplication app(argc, argv);

	auto controller = operator_controller::OperatorController::create();
	controller->run();

	return EXIT_SUCCESS;
}
