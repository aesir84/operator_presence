#pragma once

#include "IOperatorOculusRiftRenderer.h"
#include "threadsafe_queue.h"

namespace operator_view
{
	namespace opengl
	{
		class OperatorOculusRiftRenderer : public IOperatorOculusRiftRenderer
		{
			friend class OperatorRendererFactory;

		private:
			OperatorOculusRiftRenderer(std::shared_ptr<IOperatorRenderer> operatorRendererToDecorate);

		public:
			~OperatorOculusRiftRenderer();

		private:
			virtual void open() override;
			virtual void close() override;

			virtual void exec() override;

		private:
			enum class Event { Open, Render, Close };

		private:
			helpers::threadsafe_queue<Event> m_events;

		private:
			virtual void initialize(std::uint16_t eyeResolutionWidth, std::uint16_t eyeResolutionHeight) override;

			virtual void renderLeftEye() override;
			virtual void renderRightEye() override;

		private:
			virtual void registerObserver(std::shared_ptr<IOperatorViewObserver> observer) override;

			virtual void notifyHeadOrientationChanged(double yaw, double pitch, double roll) override;
			virtual void notifyErrorOccured(std::string const & errorDescription) override;

		private:
			std::vector<std::weak_ptr<IOperatorViewObserver>> m_observers;

		private:
			void startOculusVR();

		private:
			ovrSession m_ovrSession;
			ovrGraphicsLuid m_luid;
			ovrHmdDesc m_ovrHMDDescriptor;
		};
	}
}
