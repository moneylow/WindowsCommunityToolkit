//Copyright (c) Microsoft. All rights reserved. Licensed under the MIT license.
//See LICENSE in the project root for license information.

#pragma once

#include "DwellInvokedRoutedEventArgs.h"
#include "DwellProgressEventArgs.h"
#include "StateChangedEventArgs.h"

using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;

BEGIN_NAMESPACE_GAZE_INPUT

/// <summary>
/// TODO: harishsk
/// </summary>
public ref class GazeElement sealed : public DependencyObject
{
public:

    /// <summary>
    /// TODO: harishsk
    /// </summary>
    event EventHandler<StateChangedEventArgs^>^ StateChanged;

    /// <summary>
    /// TODO: harishsk
    /// </summary>
    event EventHandler<DwellInvokedRoutedEventArgs^>^ Invoked;

    /// <summary>
    /// TODO: harishsk
    /// </summary>
    event EventHandler<DwellProgressEventArgs^>^ DwellProgressFeedback;

internal:

    void RaiseStateChanged(Object^ sender, StateChangedEventArgs^ args) { StateChanged(sender, args); }

    void RaiseInvoked(Object^ sender, DwellInvokedRoutedEventArgs^ args)
    {
        Invoked(sender, args);
    }

	bool RaiseProgressFeedback(Object^ sender, DwellProgressState state, TimeSpan elapsedTime, TimeSpan triggerTime)
	{
		auto args = ref new DwellProgressEventArgs(state, elapsedTime, triggerTime);
		DwellProgressFeedback(sender, args);
		return args->Handled;
	}
};

END_NAMESPACE_GAZE_INPUT