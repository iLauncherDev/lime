#pragma once

#include <hx/CFFIPrime.h>
#include <system/ValuePointer.h>

namespace lime
{

	enum ApplicationEventType
	{

		THEME_CHANGE,
		UPDATE,
		EXIT

	};

	struct ApplicationEvent
	{
		int64_t oldFrameTimestamp;
		int64_t currentFrameTimestamp;
		double deltaTime;
		ApplicationEventType type;

		static ValuePointer *callback;
		static ValuePointer *eventObject;

		ApplicationEvent();

		static void Dispatch(ApplicationEvent *event);
	};

} // namespace lime
