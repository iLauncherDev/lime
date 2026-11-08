#include <events/ApplicationEvent.h>
#include <hx/CFFIPrime.h>

namespace lime
{

	ValuePointer *ApplicationEvent::callback = 0;
	ValuePointer *ApplicationEvent::eventObject = 0;

	ApplicationEvent::ApplicationEvent()
	{
		oldFrameTimestamp = currentFrameTimestamp = 0;
		deltaTime = 0.0;
		type = UPDATE;
	}

	value alloc_int64(int64_t val)
	{
		int32_t high = (val >> 32);
		int32_t low = val;

		value int64Value = alloc_empty_object();
		alloc_field(int64Value, val_id("high"), alloc_int(high));
		alloc_field(int64Value, val_id("low"), alloc_int(low));

		return int64Value;
	}

	void ApplicationEvent::Dispatch(ApplicationEvent *event)
	{
		if (ApplicationEvent::callback)
		{
			value object = (value)ApplicationEvent::eventObject->Get();

			alloc_field(object, val_id("oldFrameTimestamp"), alloc_int64(event->oldFrameTimestamp));
			alloc_field(object, val_id("currentFrameTimestamp"), alloc_int64(event->currentFrameTimestamp));
			alloc_field(object, val_id("deltaTime"), alloc_float(event->deltaTime));
			alloc_field(object, val_id("type"), alloc_int(event->type));

			ApplicationEvent::callback->Call();
		}
	}

} // namespace lime